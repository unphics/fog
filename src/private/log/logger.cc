#include "log/logger.hh"

#include <chrono>
// #include <ctime>
#include <fstream>

#ifdef XMAKE
std::string log_dir = "../../../";
#else
std::string log_dir = "";
#endif

namespace fog::log {

logger::logger(const std::string& logger_name) {
    this->_log_file_name = "default_log_file_name";
    this->_logger_name = logger_name;

    if (sub_dir == "") {
        auto now = ::std::chrono::system_clock::now();
        ::std::time_t now_time = ::std::chrono::system_clock::to_time_t(now) - 50;
        ::std::tm* local_time = ::std::localtime(&now_time);
        ::std::ostringstream oss;
        oss << local_time->tm_year + 1900
            << "."
            << local_time->tm_mon + 1
            << "."
            << local_time->tm_mday
            << "-"
            << local_time->tm_hour
            << "."
            << local_time->tm_min
            << "."
            << local_time->tm_sec;
        sub_dir = oss.str();
    }

    this->init();
}
void logger::init() {
    auto now = ::std::chrono::system_clock::now();
    ::std::time_t now_time = ::std::chrono::system_clock::to_time_t(now) - 50;
    ::std::tm* local_time = ::std::localtime(&now_time);
    ::std::ostringstream oss;
    oss << "Log-"
        << this->_logger_name
        << "-"
        << local_time->tm_year + 1900
        << "."
        << local_time->tm_mon + 1
        << "."
        << local_time->tm_mday
        << "-"
        << local_time->tm_hour
        << "."
        << local_time->tm_min
        << "."
        << local_time->tm_sec;
    this->_log_file_name = oss.str();
}
std::string logger::get_log_file_url() {
    return log_dir + "../log/" + this->_log_file_name + ".txt";
}
void logger::push_log(std::ostringstream& oss) {
    this->_mutex.lock();
    std::ofstream out_file(this->get_log_file_url(), std::ios::out | std::ios::app);
    if (out_file.is_open()) {
        oss << "\n";
        out_file << oss.str();
        out_file.close();
        this->_mutex.unlock();
        return;
    }
    this->_mutex.unlock();
    printf("fetal: failed to open log file !!!\n");
}

}