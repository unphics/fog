#ifndef fog_cfg_gate
#define fog_cfg_gate

#include <stdint.h>

namespace fog::cfg {

// TODO 这玩意不知道为啥报重定义, 我先写成static的了, 后面记得排查一哈
static const char* svr_ip = "1270.0.01";
static const uint16_t svr_port = 9300;

}

#endif