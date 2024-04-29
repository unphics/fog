#ifndef fog_time_scale 
#define fog_time_scale 

#include "essential.hh"
#include "time/task.hh"
#include <cstdint>
#include <array>
#include <list>
#include <vector>

namespace fog::time {

// 刻度
class scale {
public:
    scale(scale* up = nullptr): _up_scale(up) {
        this->_wheel.reserve(this->_capacity);
    }
    void tick(){
        this->handle();
        this->_cur++;
        if (this->_cur >= this->_capacity && this->_up_scale) {
            log::print("time wheel up !");
            this->_up_scale->tick();
            this->_cur = 0;
        }
    }
    virtual void handle() {
        for(auto& task : this->_wheel[this->_cur]) {}
    }
protected:
    scale* _up_scale;
    uint16_t _capacity = 10; // 容量
    uint16_t _cur = 0; // 当前
    std::vector<std::list<task>>_wheel;
};

class second: public scale {
public:
    second(scale* up = nullptr): scale(up) {
        this->_wheel.reserve(this->_capacity);
    }
    virtual void handle() {
        log::print("second", this->_cur);
        for(auto it = this->_wheel[this->_cur].begin(); it != this->_wheel[this->_cur].end(); ++it) {

        }
    }
};

class minute: public scale {
public:
    minute(scale* up = nullptr): scale(up) {
        this->_wheel.reserve(this->_capacity);
    }
    virtual void handle() {
        log::print("minute", this->_cur);
        for(auto it = this->_wheel[this->_cur].begin(); it != this->_wheel[this->_cur].end(); ++it) {

        }
    }
};

}

#endif