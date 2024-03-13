#ifndef fog_log_log
#define fog_log_log

#include "actor/session.hh"

namespace fog::log {

class log: public actor::session {
public:
    log(::fog::actor::def def);
    virtual void start() override;
protected:
    virtual void _deal(std::unique_ptr<::fog::actor::task> task);
};

}

#endif