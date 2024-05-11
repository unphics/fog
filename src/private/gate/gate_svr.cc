#include "gate/gate_svr.hh"

#include "login.pb.h"

#include "pb/pb.hh"

#include "log/logger.hh"
#include "cfg/cfg.hh"
// #include "bot/gate_bot.hh"
#include <string>

namespace fog::gate {

gate_svr::gate_svr(const std::string svr_name, center::center_svr* center): svr_base(svr_name), _center(center) {}
gate_svr::~gate_svr() {
    delete this->_io_svc;
    delete this->_udp_sock;
    delete this->_saddr;
}
void gate_svr::svr_run() {
    this->svr_base::svr_run();
    this->_io_svc = new boost::asio::io_service; // 一个服务的类, 给这个udp通信初始化
    this->_udp_sock = new boost::asio::ip::udp::socket(*this->_io_svc); // 给这个udp通信初始化
    this->_saddr = new boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(::fog::cfg::svr_ip), ::fog::cfg::svr_port); // 绑定ip和port
    this->_udp_sock->open(this->_saddr->protocol()); // 添加协议
    this->_udp_sock->bind(*this->_saddr);
    char buf[1024];
    ::memset(buf, 0, 1024);
    this->_logger->print("gate sock begin");
    while (!this->_stop) {
        boost::asio::ip::udp::endpoint* caddr = new boost::asio::ip::udp::endpoint;
        this->_udp_sock->receive_from(boost::asio::buffer(buf, 1024), *caddr);
        login::CSReqLogin recv;
        auto [proto, len] = fog::pb::parse_pb(buf, &recv);
        this->_logger->print("gate recv ::", len, proto, recv.account(), recv.password());
        delete caddr;
    }
}

}