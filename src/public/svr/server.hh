#ifndef fog_svr_server
#define fog_svr_server

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