#ifndef fog_svr_svr_base
#define fog_svr_svr_base

#include <stdint.h>
#include <string>
#include <vector>
#include <memory>
#include <atomic>

namespace fog::log {class logger;}

namespace fog::svr {

class svr_base {
public:
    svr_base(const std::string& name);
    virtual ~svr_base();
    const std::string name();
    virtual void stop();
    virtual void svr_run();
protected:
    uint16_t _id;
    std::string _name;
    std::vector<std::shared_ptr<svr_base>> _other_svrs;
    typename ::fog::log::logger* _logger;
    std::atomic_bool _stop;
};

}

#endif