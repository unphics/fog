
#ifndef fog_gate_gate_svr
#define fog_gate_gate_svr

#include "svr/svr_base.hh"

#include <boost/asio.hpp>

#include <condition_variable>
#include <mutex>
#include <memory>

namespace fog::center{class center_svr;}

namespace fog::gate {

class gate_svr: public ::fog::svr::svr_base {
public:
    gate_svr(const std::string svr_name, center::center_svr* center);
    virtual ~gate_svr();
    virtual void svr_run() override;
protected:
    void deal_msg(boost::asio::ip::udp::endpoint caddr, uint16_t proto, uint16_t len, std::unique_ptr<char[]> msg);
    boost::asio::io_service* _io_svc;
    boost::asio::ip::udp::socket* _udp_sock;
    center::center_svr* _center;
    boost::asio::ip::udp::endpoint* _saddr; // field: address(), port()
};

}

#endif