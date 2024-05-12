#ifndef fog_login_anonym_task
#define fog_login_anonym_task

#include <boost/asio.hpp>

#include <memory>
#include <stdint.h>

namespace fog::login {

class anonym_task {
public:
    anonym_task(boost::asio::ip::udp::endpoint caddr, uint16_t proto, uint16_t len,
        std::unique_ptr<char[]> msg): caddr(caddr), proto(proto), len(len), msg(std::move(msg)) {}
    boost::asio::ip::udp::endpoint caddr;
    uint16_t proto;
    uint16_t len;
    std::unique_ptr<char[]> msg;
};

}

#endif