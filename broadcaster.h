//
// Created by Lasse Lauritsen on 25/03/16.
//

#ifndef BOOSTMULTICASTEXAMPLE_BROADCASTER_H
#define BOOSTMULTICASTEXAMPLE_BROADCASTER_H

#include <boost/asio.hpp>
#include <boost/array.hpp>

class broadcaster {
public:
    broadcaster(boost::asio::io_service& io_service, const boost::asio::ip::address multicast_address);
    void send_message(const std::string& msg);
private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint endpoint_;
    void handle_send(const boost::system::error_code &error, size_t bytes_send);
};


#endif //BOOSTMULTICASTEXAMPLE_BROADCASTER_H
