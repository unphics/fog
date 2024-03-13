#ifndef fog_actor_tick
#define fog_actor_tick

#include "actor/actor.hh"

namespace fog::actor {

enum class def;

class tick : public actor {
public:
    tick(::fog::actor::def def);
    virtual void start() override;
protected:
    virtual void _tick();
};

}

#endif