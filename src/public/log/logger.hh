#ifndef fog_log_logger
#define fog_log_logger

/**
 * @file logger.hh
 * @date Tue Apr 30 2024 00:04:01 GMT+0800 (中国标准时间)
 * @author zys
 * @version 0.1
 * @brief 日志器
 */

#include "log/print.hh"

#include <string>
#include <sstream>
#include <mutex>

namespace fog::log {

static std::string sub_dir = "";

class logger {
public:
    logger(const std::string& logger_name);
    template<typename... Args>
    void print(Args... argv) {
        std::ostringstream oss = make_print_oss(argv...);
        std::cout << oss.str() << std::endl;
        this->push_log(oss);
    }
    std::string get_log_file_url();
    void push_log(std::ostringstream& oss);
private:
    void init();
    std::string _log_file_name;
    std::mutex _mutex;
    std::string _logger_name;
};

}

#endif