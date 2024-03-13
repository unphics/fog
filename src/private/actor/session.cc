#include "actor/session.hh"

#include "essential.hh"
#include "actor/task.hh"
#include "actor/def.hh"

namespace fog::actor {

session::session(::fog::actor::def def): actor(def) {

}
void session::start() {
    print("actor start on thread:", ::syscall(SYS_gettid));
    this->_session();
}
void session::_session() {
    while (this->_stop == false) {
        std::unique_ptr<task> task;
        {
            std::unique_lock<std::mutex> lock(this->_mutex);
            this->_cond.wait(lock, [this] {
                return this->_stop == false && this->_queue.empty() == false;
            });
            if (this->_stop == true || this->_queue.empty() == true) {
                return;
            }
            task = std::move(this->_queue.front());
            this->_queue.pop();
        }
        this->_deal(std::move(task));
    }
}
void session::_deal(std::unique_ptr<task> task) {
    print("[deal] thread", ::syscall(SYS_gettid),"deal task:", task->id);
}

}