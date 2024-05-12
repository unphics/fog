#ifndef fog_log_print
#define fog_log_print

#include <iostream>
#include <chrono>
#include <sstream>
#include <memory>

namespace fog::log {

template<typename T>
void _recurse_cout(std::ostringstream& oss, T t) {
    oss << t;
}

template<typename T, typename... Args>
void _recurse_cout(std::ostringstream& oss, T t, Args... args) {
    oss << t; // oss << " " << t;
    _recurse_cout(oss, args...);
}

template<typename... Args>
std::ostringstream make_print_oss(Args... args) {
    auto now = std::chrono::system_clock::now(); // 当前系统时间点
    std::time_t now_time = std::chrono::system_clock::to_time_t(now) - 50; // 转换为时间戳, 这个50不知道是啥, 可能是北京和珠海的时差?
    std::tm* local_time = std::localtime(&now_time);
    std::ostringstream oss;
    oss << "["
        << local_time->tm_year + 1900 << "/"
        << local_time->tm_mon + 1 << "/"
        << local_time->tm_mday << "-"
        << local_time->tm_hour << ":"
        << local_time->tm_min << ":"
        << local_time->tm_sec
        <<"] Print :";
    _recurse_cout(oss, args...);
    return oss;
}

void print_draw_only(std::ostringstream oss);

template<typename... Args>
void print(Args... args) {
    std::ostringstream oss(std::move(::fog::log::make_print_oss(args...)));
    // std::unique_ptr<::fog::actor::task> unique = std::make_unique<::fog::log::task>(new std::ostringstream(std::move(oss)));
    // ::fog::actor::mgr::inst()->send(::fog::actor::def::log, std::move(unique));
    // TODO 废弃掉
}

}
#endif