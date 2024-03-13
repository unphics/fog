#ifndef fog_time_time
#define fog_time_time

#include "time/task.hh"
#include "time/scale.hh"

#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <array>

namespace fog::time {

class timesvr {
public:
    void init();
    void tick();
    ~timesvr();
private:
    minute* _minute;
    second* _second;
};

class wheel {
public:
    wheel() {}
private:
    int _tick; // 当前的秒针, 走到哪里释放哪里, 相当于执行哪里的任务
    int _capacity; // 表盘最大数量, 即最大延迟时间
    std::vector<std::vector<std::shared_ptr<task>>> _wheel;
    std::unordered_map<uint64_t, std::weak_ptr<task>> _timers;
};

}

#endif