
#ifndef fog_gate_gate_svr
#define fog_gate_gate_svr

#include "svr/svr_base.hh"

#include <condition_variable>
#include <mutex>

namespace fog::gate {

class gate_svr: public ::fog::svr::svr_base {
public:
    gate_svr(const std::string svr_name);
    virtual ~gate_svr();
    virtual void svr_run() override;
protected:
};

}

#endif