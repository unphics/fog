#ifndef fog_actor_actor
#define fog_actor_actor

// #include "def.hh"

#include <queue>
#include <condition_variable>
#include <mutex>
#include <functional>
#include <atomic>
#include <memory>

namespace fog::actor {

enum class def;
class task;

class actor {
public:
    actor(::fog::actor::def def);
    actor() {};
    virtual ~actor();
    virtual void start() = 0;
    /**
     * 用于接收外部mgr转发的task
     */
    virtual void dispatch(std::unique_ptr<task> task);
    virtual void stop();
    /**
     * 描述这个actor实例的负载程度
     */
    uint32_t load();
    typename ::fog::actor::def def();
protected:
    std::atomic_bool _stop;
    std::queue<std::unique_ptr<task>> _queue;
    std::condition_variable _cond;
    std::mutex _mutex;
    typename ::fog::actor::def _def;
};

}

#endif