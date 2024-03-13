#ifndef fog_time_task
#define fog_time_task

#include <functional>
#include <cstdint>

namespace fog::time {

class task {
public:
    task(uint16_t id, uint32_t delay, const std::function<void()>& cb): _id(id), _timeout(delay),
        _task_cb(cb), _canceled(false) {}
    ~task() {
        if (this->_canceled == false) {
            this->_task_cb();
        }
        this->_release();
    }
    void cancel() {
        this->_canceled = true;
    }
    void set_release(const std::function<void()>& cb) {
        this->_release = cb;
    }
    uint32_t delay_time() {
        return this->_timeout;
    }
private:
    uint16_t _id;
    uint32_t _timeout; // 超时时间
    bool _canceled; // 是否被取消
    std::function<void()> _task_cb; // 定时器要执行的定时任务
    std::function<void()> _release; // 用于删除wheel中保存的定时器对象信息
};

}

#endif