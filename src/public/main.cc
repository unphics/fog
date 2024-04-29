
#include "essential.hh"
#include "actor/mgr.hh"
#include "actor/task.hh"
#include "saa/saa.hh"
#include "actor/session.hh"
#include "time/time.hh"

int main(int argc, char** argv) {

#pragma region init
    ::fog::log::raw_push_log(::fog::log::raw_print_oss("gcc version:", __GNUC__));
    ::fog::log::raw_push_log(::fog::log::raw_print_oss("current cpp version:", __cplusplus));
#ifdef XMAKE
    ::fog::log::raw_push_log(::fog::log::raw_print_oss("use xmake build"));
#endif
    ::fog::log::raw_push_log(::fog::log::raw_print_oss("main thread id is:", ::syscall(SYS_gettid)));
#pragma endregion init

    fog::actor::mgr::inst()->create<fog::actor::def::log>();
    fog::actor::mgr::inst()->create<fog::actor::def::session>();
    fog::actor::mgr::inst()->create<fog::actor::def::session>();
    fog::actor::mgr::inst()->create<fog::actor::def::session>();

    ::sleep(1);
    for(uint16_t i = 0; i < 20; ++i) {
        auto task = std::make_unique<fog::actor::task>();
        task->id = 1000 + i;
        fog::actor::mgr::inst()->send(fog::actor::def::session, std::move(task));
    }

    // fog::saa::saa();

    // fog::time::timesvr timesvr;
    // timesvr.init();
    // while (true) {
    //     timesvr.tick();
    //     ::sleep(1);
    // }

    ::sleep(20);
    return 0;
}