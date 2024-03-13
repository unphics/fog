#ifndef fog_log_logger
#define fog_log_logger

#include <string>
#include <sstream>
#include <mutex>

namespace fog::log {

class logger {
public:
    static logger*  get_inst();
    std::string get_log_file_url();
    void push_log(std::ostringstream& oss);
private:
    void init();
    logger();
    inline static logger* _singleton {nullptr};
    std::string _log_file_name;
    std::mutex _mutex;
};

}

#endif