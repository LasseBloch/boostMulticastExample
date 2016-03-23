//
// Created by Lasse Lauritsen on 23/03/16.
//

#include "receiver.h"

receiver::receiver(boost::asio::io_service &io_service, const boost::asio::ip::address &listen_address,
                   const boost::asio::ip::address &multicast_address) : socket_(io_service) {

}

