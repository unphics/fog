#include "log/log.hh"

#include "essential.hh"

#include <memory>

namespace fog::log {

log::log(::fog::actor::def def): session(def) {
    // fog::log::logger::get_inst()->init();
}

void log::start() {
    // this->session::start();
    this->_session();
}

void log::_deal(std::unique_ptr<::fog::actor::task> task) {
    // print("[deal] thread", ::syscall(SYS_gettid),"deal task:", task->id, ",",task->desc);
    if (dynamic_cast<::fog::actor::task*>(task.get())) {
        ::fog::log::task* t = static_cast<::fog::log::task*>(task.release());
        std::cout << t->oss()->str() << std::endl;
        fog::log::logger::get_inst()->push_log(*t->oss());
        delete t;
    } else {
        // print("fatal: ");
    }
}

}