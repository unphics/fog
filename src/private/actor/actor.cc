#include "actor/actor.hh"

#include "essential.hh"
#include "actor/task.hh"
#include "actor/def.hh"

namespace fog::actor {

actor::actor(::fog::actor::def def): _stop(false), _def(def) {
    
}
actor::~actor() {
    this->stop();
}
void actor::dispatch(std::unique_ptr<task> task) {
    {
        std::lock_guard<std::mutex> guard(this->_mutex);
        this->_queue.push(std::move(task));
    }
    this->_cond.notify_one();
}
void actor::stop() {
    if (this->_stop == true) {
        return;
    }
    this->_stop = true;
    this->_cond.notify_all();
}
uint32_t actor::load() {
    uint32_t load = 0;
    load += this->_queue.size();
    return load;
}
typename ::fog::actor::def actor::def() {
    return this->_def;
}

}