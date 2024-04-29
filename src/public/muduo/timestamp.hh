#pragma once

#include <iostream>
#include "essential.hh"
#include <string>

namespace fog::muduo {

class timestamp {
public:
    timestamp();
    timestamp(int64_t sec_since_epoch);
    ~timestamp();
    static timestamp now();
    time_t to_int() const;
    std::string to_str() const;
private:
    time_t _sec_since_epoch;
};

}