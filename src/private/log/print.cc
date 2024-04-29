#include "log/print.hh"

namespace fog::log {

void print_draw_only(std::ostringstream oss) {
    std::cout << oss.str() << std::endl;
    // fog::log::logger::get_inst()->push_log(oss);
}

}