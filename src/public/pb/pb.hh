#ifndef fog_pb_pb
#define fog_pb_pb

#include "login.pb.h"

#include <boost/asio.hpp>

#include <string>
#include <type_traits>

namespace fog::pb {

template<typename T, typename B>
void send_udp(boost::asio::ip::udp::socket* udp_sock, boost::asio::ip::udp::endpoint* tar_addr, B* pb_obj) {
    T* pb_msg = static_cast<T*>(pb_obj);
    uint16_t len = pb_msg->ByteSizeLong();
    uint16_t size_u16 = sizeof(uint16_t);
    uint16_t size_buf = len + 2 * size_u16;
    char buf[size_buf];
    ::memset(buf, 0, size_buf);
    char arr[len];
    pb_msg->SerializeToArray(arr, len);
    ::memcpy(buf, &len, size_u16);
    uint16_t proto = 10001;
    ::memcpy(buf + size_u16, &proto, size_u16);
    ::memcpy(buf + 2 * size_u16, arr, len);
    udp_sock->send_to(boost::asio::buffer(buf, size_buf), *tar_addr);
}

}

#endif