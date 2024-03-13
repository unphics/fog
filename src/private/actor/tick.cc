#include "actor/tick.hh"

#include "essential.hh"
#include "actor/def.hh"

namespace fog::actor {

tick::tick(::fog::actor::def def): actor(def)  {
    
}
void tick::start() {
    print("actor start on thread:", ::syscall(SYS_gettid));
    this->_tick();
}
void tick::_tick() {
    while(this->_stop == false) {

    }
}

}