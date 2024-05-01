#ifndef fog_gate_gate_svr
#define fog_gate_gate_svr

#include "svr/svr_base.hh"

#include <condition_variable>
#include <mutex>

namespace fog::gate {

class gate_svr: public ::fog::svr::svr_base {
public:
    gate_svr(const std::string svr_name);
protected:
    virtual void _svr_run() override;
    std::condition_variable _cond;
    std::mutex _mutex;
};

}

#endif