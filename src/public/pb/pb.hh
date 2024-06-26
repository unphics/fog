#ifndef fog_pb_pb
#define fog_pb_pb

#include "login.pb.h"

#include <boost/asio.hpp>

#include <string>
#include <memory>
#include <type_traits>
#include <tuple>

namespace fog::pb {

template<typename T>
void send_udp(boost::asio::ip::udp::socket* udp_sock, boost::asio::ip::udp::endpoint* tar_addr, auto* pb_obj) {
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

/**
 * @notice 此方法会顺手清空buf
 */
template<typename T>
std::tuple<uint16_t, uint16_t> parse_msg(char* buf, T* recv) {
    uint16_t len = 0;
    uint16_t size_u16 = sizeof(uint16_t);
    ::memcpy(&len, buf, size_u16);
    uint16_t proto = 0;
    ::memcpy(&proto, buf + size_u16, size_u16);
    char msg[len];
    ::memset(msg, 0, len);
    ::memcpy(msg, buf + 2 * size_u16, len);
    recv->ParseFromArray(msg, len);
    ::memset(buf, 0, 1024);
    return std::make_tuple(proto, len);
}

static auto split_msg(char* buf) {
    uint16_t len = 0;
    uint16_t size_u16 = sizeof(uint16_t);
    ::memcpy(&len, buf, size_u16);
    uint16_t proto = 0;
    ::memcpy(&proto, buf + size_u16, size_u16);
    char* msg = new char[len];
    ::memset(msg, 0, len);
    ::memcpy(msg, buf + 2 * size_u16, len);
    ::memset(buf, 0, 1024);
    std::unique_ptr<char[]> unique_msg(msg);
    return std::make_tuple(std::move(unique_msg), proto, len);
}

}

#endif