#include "essential.hh"

#include <cstring>
#include <iostream>
#include <signal.h>

#include "proto/test.pb.h"

#include "muduo/tcpsvr.hh"
#include "muduo/echosvr.hh"

namespace fog::muduo {

fog::muduo::echosvr* echosvr;

void shut_down(int sig) {
    print("[signal] : recv sig: %d", sig);
    // 调用echosvr::shut_down()函数停止服务
    echosvr->shut_down();
    delete echosvr;
    print("has shut down");
    ::exit(0);
}

void echo_svr_test() {
    
    ::signal(SIGTERM, shut_down);
    ::signal(SIGINT, shut_down);

    
    // echosvr = new fog::muduo::echosvr("0.0.0.0", 8765, 4, 2);
    // echosvr->start();
}

}


