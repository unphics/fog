#ifndef fog_pb_example
#define fog_pb_example

#include "login.pb.h"

#include <stdint.h>
#include <iostream>
#include <string>

namespace fog::pb {

void example() {
    login::CSReqLogin msg;
    msg.set_account(10001);
    msg.set_password("100001");
    // std::string msg_str;
    uint16_t len = msg.ByteSizeLong();
    char arr[len];
    msg.SerializeToArray(arr, len);
    // std::cout << "pb::example() :" << arr << ", " << len << std::endl;

    login::CSReqLogin re;
    re.ParseFromArray(arr, len);
    std::cout << "pb::example() :" << re.account() << ", " << re.password() << std::endl;
}

}

#endif