#ifndef fog_actor_session
#define fog_actor_session

#include "actor/actor.hh"
#include "task.hh"

namespace fog::actor {

enum class def;

class session : public actor {
public:
    session(::fog::actor::def def);
    virtual void start();
protected:
    virtual void _session();
    virtual void _deal(std::unique_ptr<task> task);
};

}

#endif