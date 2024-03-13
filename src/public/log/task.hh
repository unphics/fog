#ifndef fog_log_task
#define fog_log_task

#include "actor/task.hh"

#include <sstream>

namespace fog::log {

class task: public actor::task {
public:
    task(std::ostringstream* oss) {
        this->_oss = oss;
        this->desc = "log";
    }
    virtual ~task() {}
    std::ostringstream* oss() {
        return this->_oss;
    }
protected:
    std::ostringstream* _oss;
};

}

#endif