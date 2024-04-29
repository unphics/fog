#ifndef fog_svr_server
#define fog_svr_server

/**
 * @file server.hh
 * @date Mon Apr 29 2024 21:53:28 GMT+0800 (中国标准时间)
 * @author zys
 * @version 0.1
 * @brief 服务基类
 */

#include <stdint.h>
#include <string>
#include <vector>
#include <memory>

namespace fog::svr::server {

class server {
public:
    server();
protected:
    uint16_t id;
    std::string name;
    std::vector<std::shared_ptr<server>> svrs;
};

}

#endif