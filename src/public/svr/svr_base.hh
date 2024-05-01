#ifndef fog_svr_svr_base
#define fog_svr_svr_base

/**
 * @file svr_base.hh
 * @date Mon Apr 29 2024 21:53:28 GMT+0800 (中国标准时间)
 * @author zys
 * @version 0.1
 * @brief 服务基类
 */

#include <stdint.h>
#include <string>
#include <vector>
#include <memory>
#include <atomic>

namespace fog::log {
class logger;
}

namespace fog::svr {

class svr_base {
public:
    svr_base(const std::string& name);
    const std::string name();
    virtual void stop();
protected:
    virtual void _svr_run();
    uint16_t _id;
    std::string _name;
    std::vector<std::shared_ptr<svr_base>> _other_svrs;
    typename ::fog::log::logger* _logger;
    std::atomic_bool _stop;
};

}

#endif