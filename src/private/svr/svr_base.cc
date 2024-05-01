#include "svr/svr_base.hh"


namespace fog::svr {

svr_base::svr_base(const std::string& name): _name(name) {
    
}
const std::string svr_base::name() {
    return this->_name;
}
void svr_base::stop() {

}
void svr_base::_svr_run() {

}

}