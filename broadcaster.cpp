//
// Created by Lasse Lauritsen on 25/03/16.
//

#include "broadcaster.h"
#include <iostream>
#include <boost/bind.hpp>

const int port = 1900;

broadcaster::broadcaster(boost::asio::io_service &io_service,
                         const boost::asio::ip::address multicast_address) : socket_(io_service), endpoint_(multicast_address, port) {
    // Create endpoint
    socket_.open(endpoint_.protocol());
}

void broadcaster::send_message(const std::string& msg) {
    if (socket_.is_open()) {
        socket_.async_send_to(boost::asio::buffer(msg),
                              endpoint_,
                              boost::bind(
                                      &broadcaster::handle_send,
                                      this,
                                      boost::asio::placeholders::error,
                                      boost::asio::placeholders::bytes_transferred
                              )
        );
    }
    else {
        std::cerr << "Socket not open!" << std::endl;
    }

}

void broadcaster::handle_send(const boost::system::error_code& error, size_t bytes_send) {
    std::cout << "Error code: " << error << " size of transmitted data: " << bytes_send << std::endl;
}