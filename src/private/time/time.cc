#include "time/time.hh"

namespace fog::time {

void timesvr::init() {
    this->_minute = new minute();
    this->_second = new second(this->_minute);
}

void timesvr::tick() {
    this->_second->tick();
}

timesvr::~timesvr() {
    delete this->_second;
    delete this->_minute;
}

}