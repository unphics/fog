#include "center/center_svr.hh"

#include "essential.hh" // sleep
#include "log/logger.hh"
#include "gate/gate_svr.hh"
#include "login/login_svr.hh"

#include <thread>

namespace fog::center {

center_svr::center_svr(std::string name): svr_base(name) {}
center_svr::~center_svr() {
    delete this->_gate;
    delete this->_login;
}
void center_svr::svr_run() {
    this->svr_base::svr_run();
    this->run_gate();
    this->run_login();
}
void center_svr::tick() {
    while(!this->_stop) {
        this->_logger->print("center_svr::tick");
        ::sleep(1);
    }
}
void center_svr::run_gate() {
    std::jthread jthd([this] {
        this->_gate = new gate::gate_svr("gate", this);
        this->_gate->svr_run();
    });
    jthd.detach();
}
void center_svr::run_login() {
    std::jthread jthd([this] {
        this->_login = new login::login_svr("gate", this);
        this->_login->svr_run();
    });
    jthd.detach();
}
login::login_svr* center_svr::login() {
    return this->_login;
}

}