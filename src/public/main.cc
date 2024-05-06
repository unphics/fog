
#include "essential.hh"
#include "actor/mgr.hh"
#include "actor/task.hh"
#include "actor/session.hh"
#include "time/time.hh"
#include "log/logger.hh"

int main(int argc, char** argv) {

#if 0
    ::fog::log::print_draw_only(::fog::log::make_print_oss("gcc version:", __GNUC__));
    ::fog::log::print_draw_only(::fog::log::make_print_oss("current cpp version:", __cplusplus));
#ifdef XMAKE
    ::fog::log::print_draw_only(::fog::log::make_print_oss("use xmake build"));
#endif
    ::fog::log::print_draw_only(::fog::log::make_print_oss("main thread id is:", ::syscall(SYS_gettid)));

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
#endif
    fog::log::logger logger("MainThread");
    logger.print("qqq", "www");
    ::sleep(20);
    return 0;
}