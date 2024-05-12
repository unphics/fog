#ifndef fog_login_login_svr
#define fog_login_login_svr

#include "svr/svr_base.hh"

#include <boost/asio.hpp>

#include <mutex>
#include <condition_variable>
#include <memory>
#include <stdint.h>
#include <queue>

namespace fog::center{class center_svr;}

namespace fog::login {

class anonym_task;

class login_svr: public ::fog::svr::svr_base {
public:
    login_svr(const std::string svr_name, center::center_svr* center);
    virtual ~login_svr();
    virtual void svr_run() override;
    void anonym_msg(boost::asio::ip::udp::endpoint caddr, uint16_t proto, uint16_t len, std::unique_ptr<char[]> msg);
private:
    void work();
    void deal_anonym();
    std::mutex _login_mutex;
    std::condition_variable _login_cond;
    
    center::center_svr* _center;
    std::queue<anonym_task*> _anonym_queue;
    std::mutex _anonym_queue_mutex;
};

} // namespace login


#endif