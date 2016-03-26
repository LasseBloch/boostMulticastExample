//
// Created by Lasse Lauritsen on 23/03/16.
//

#ifndef BOOSTMULTICASTEXAMPLE_RECEIVER_H
#define BOOSTMULTICASTEXAMPLE_RECEIVER_H

#include <boost/asio.hpp>

class receiver {
public:
    receiver(boost::asio::io_service& io_service,
    const boost::asio::ip::address& listen_address,
    const boost::asio::ip::address& multicast_address);
    void handle_receive_from(const boost::system::error_code& error, size_t bytes_recvd);
private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    const static int MAX_LEN = 1024;
    char data_[MAX_LEN];
};


#endif //BOOSTMULTICASTEXAMPLE_RECEIVER_H
