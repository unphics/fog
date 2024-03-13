#ifndef fog_actor_task
#define fog_actor_task

#include <cstdint>
#include <string>

namespace fog::actor {

class task {
public:
    task() = default;
    virtual ~task() = default;
    uint64_t id;
    std::string desc = "default";
private:
};

}

#endif