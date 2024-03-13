#ifndef fog_actor_mgr
#define fog_actor_mgr

// #include "essential.hh"
#include "actor/actor.hh"
#include "def.hh"
#include "task.hh"

#include <vector>
#include <map>
#include <memory>
#include <type_traits>
#include <thread>

namespace fog::actor {

class actor;

class mgr {
public:
    mgr();
    // template<typename T, typename = std::enable_if_t<std::is_base_of_v<actor, T>>>
    template<def D>
    void create() {
        std::jthread jthd([this]() mutable {
            std::unique_ptr<def_class_t<D>> unique = std::make_unique<def_class_t<D>>(D);
            ::fog::actor::def def = unique->def();
            this->_actors[def].push_back(std::move(unique));
            this->_actors[def][this->_actors[def].size() - 1]->start();
        });
        jthd.detach();
    }
    void send(def def, std::unique_ptr<task> task);
    static mgr* inst() {
        if (mgr::_singleton) {
            return mgr::_singleton;
        }
        mgr::_singleton = new mgr;
        return mgr::_singleton;
    }
private:
    inline static mgr* _singleton {nullptr};
    std::map<def, std::vector<std::unique_ptr<actor>>> _actors;
};

}

#endif