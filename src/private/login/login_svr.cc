#include "login/login_svr.hh"

#include "center/center_svr.hh"
#include "login/anonym_task.hh"
#include "log/logger.hh"
#include "login.pb.h"

namespace fog::login {

login_svr::login_svr(const std::string svr_name, center::center_svr* center): 
    svr_base(svr_name), _center(center) {
    
}
login_svr::~login_svr() {}
void login_svr::svr_run() {
    this->svr_base::svr_run();
    {
        std::unique_lock<std::mutex> lock(this->_login_mutex);
        this->_login_cond.wait(lock, [this] {
            // 执行条件
            return this->_stop == false && this->_anonym_queue.empty() == false;
        });
        // 退出条件
        if (this->_stop == true || this->_anonym_queue.empty() == true) {
            return;
        }
        this->work();
    }
}
void login_svr::anonym_msg(boost::asio::ip::udp::endpoint caddr, uint16_t proto, uint16_t len, std::unique_ptr<char[]> msg){
    anonym_task* task = new anonym_task(caddr, proto, len, std::move(msg));
    {
        std::lock_guard<std::mutex> guard(this->_anonym_queue_mutex);
        this->_anonym_queue.push(task);
    }
    this->_login_cond.notify_one();
    // switch (proto) {
    //     case: 10001:
    //         login::CSReqLogin req;
    //         req.ParseFromArray(msg.get(), len);
    //     default: break;
    // }
}
void login_svr::work() {
    this->deal_anonym();
}
void login_svr::deal_anonym() {
    if (this->_anonym_queue.empty()) {
        return;
    }
    anonym_task* anonym = this->_anonym_queue.front();
    this->_anonym_queue.pop();

    uint16_t proto = anonym->proto;
    switch (proto) {
        case 10001: {
            ::login::CSReqLogin req;
            req.ParseFromArray(anonym->msg.get(), anonym->len);
            this->_logger->print("login_svr::deal_anonym ", req.account());
            break;
        }
        default: this->_logger->print("undefined proto: ", proto); break;
    }
}

}