//
// Created by Lasse Lauritsen on 23/03/16.
//

#include "receiver.h"
#include <iostream>

const int multicast_port = 1900;

receiver::receiver(boost::asio::io_service &io_service,
                   const boost::asio::ip::address& listen_address,
                   const boost::asio::ip::address& multicast_address) : socket_(io_service) {
    // create the socket so that multiple may bound to the same address.
    boost::asio::ip::udp::endpoint listen_endpoint(listen_address, multicast_port);
    socket_.open(listen_endpoint.protocol());
    socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
    socket_.bind(listen_endpoint);

    // join the multicast group
    socket_.set_option(boost::asio::ip::multicast::join_group(multicast_address));

    socket_.async_receive_from(boost::asio::buffer(data_, MAX_LEN),
                               sender_endpoint_,
                               boost::bind(
                                       &receiver::handle_receive_from,
                                       this,
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred
                               )
    );

}

void receiver::handle_receive_from(const boost::system::error_code &error, size_t bytes_recvd) {
    if (!error) {
        std::cout.write(data_, bytes_recvd);
        std::cout << std::endl;

        socket_.async_receive_from(boost::asio::buffer(data_, MAX_LEN),
                                   sender_endpoint_,
                                   boost::bind(
                                           &receiver::handle_receive_from,
                                           this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred
                                   )

        );
    }
}
