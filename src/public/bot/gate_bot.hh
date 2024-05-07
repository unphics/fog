#ifndef fog_bot_gate_bot
#define fog_bot_gate_bot

#include "cfg/cfg.hh"

#include <iostream>
#include <boost/asio.hpp>
#include <string>
namespace fog::bot {

void gate_bot_01() {
    std::cout << "gate_bot_01 begin" << std::endl;
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket udp_sock(io_service);
    boost::asio::ip::udp::endpoint local_addr(boost::asio::ip::address::from_string(::fog::cfg::svr_ip), ::fog::cfg::svr_port);
    udp_sock.open(local_addr.protocol());
    char buf[1024] = {0};
    std::string send_str("msg send");
    udp_sock.send_to(boost::asio::buffer(send_str.c_str(), 1024), local_addr);
    std::cout << "gate_bot_01 end" << std::endl;
}

}

#endif