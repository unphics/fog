#ifndef fog_bot_bot
#define fog_bot_bot

#include <stdint.h>
#include <functional>
#include <thread>
#include <iostream>

#include "essential.hh"

namespace fog::bot {

void run_bot(uint16_t delay, std::function<void()> bot_fn) {
    ::sleep(delay);
    std::jthread jthd([&] {
        std::cout << "run_bot" << std::endl;
        bot_fn();
    });
}

}

#endif