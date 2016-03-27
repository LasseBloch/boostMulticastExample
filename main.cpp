#include <iostream>
#include <boost/asio.hpp>
#include "receiver.h"
#include "broadcaster.h"

using namespace std;

int main() {
    try {
        boost::asio::io_service io;
        boost::asio::ip::address listen_addr = boost::asio::ip::address::from_string("0.0.0.0");
        boost::asio::ip::address multicast_addr = boost::asio::ip::address::from_string("239.255.255.250");
        int port = 1900;
        receiver rev(io, listen_addr, multicast_addr, port);
        broadcaster bcaster(io, multicast_addr, port);

        for(int n = 0; n < 2; n++) {
            bcaster.send_ssdp_discover();
        }

        io.run();
    } catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}