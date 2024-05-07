#include "gate/gate_svr.hh"

#include "log/logger.hh"
#include "cfg/cfg.hh"
// #include "bot/gate_bot.hh"

#include <boost/asio.hpp>

namespace fog::gate {

gate_svr::gate_svr(const std::string svr_name):svr_base(svr_name) {}
gate_svr::~gate_svr() {}
void gate_svr::svr_run() {
    boost::asio::io_service io_service; // 一个服务的类, 给这个udp通信初始化
    boost::asio::ip::udp::socket udp_sock(io_service); // 给这个udp通信初始化
    boost::asio::ip::udp::endpoint local_addr(boost::asio::ip::address::from_string(::fog::cfg::svr_ip), ::fog::cfg::svr_port); // 绑定ip和port
    udp_sock.open(local_addr.protocol()); // 添加协议
    udp_sock.bind(local_addr);
    char buf[1024] = {0};
    while(!this->_stop) {
        boost::asio::ip::udp::endpoint sendpoint;
        this->_logger->print("gate sock begin");
        udp_sock.receive_from(boost::asio::buffer(buf, 1024), sendpoint);
        this->_logger->print("gate recv :: ", buf);

        memset(buf, 0, 1024);
    }
}

}