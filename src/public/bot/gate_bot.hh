#ifndef fog_bot_gate_bot
#define fog_bot_gate_bot

#include "login.pb.h"

#include "cfg/cfg.hh"
#include "pb/pb.hh"

#include <stdint.h>
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
void gate_bot_login() {
    std::cout << "gate_bot_login begin" << std::endl;
    boost::asio::io_service io_service;
    boost::asio::ip::udp::socket udp_sock(io_service);
    boost::asio::ip::udp::endpoint local_addr(boost::asio::ip::address::from_string(::fog::cfg::svr_ip), ::fog::cfg::svr_port);
    udp_sock.open(local_addr.protocol());
    login::CSReqLogin msg;
    msg.set_account(10002);
    msg.set_password("100002");
    pb::send_udp<login::CSReqLogin>(&udp_sock, &local_addr, &msg);
    std::cout << "gate_bot_login end" << std::endl;
}

}

#endif