#include <iostream>
#include <boost/asio.hpp>
#include "receiver.h"

using namespace std;

int main() {
    try {
        boost::asio::io_service io;
        boost::asio::ip::address listen_addr = boost::asio::ip::address::from_string("0.0.0.0");
        boost::asio::ip::address multicast_addr = boost::asio::ip::address::from_string("239.255.0.1");

        receiver rev(io, listen_addr, multicast_addr);
        io.run();
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}