#include "svr/svr_base.hh"

#include "log/logger.hh"

namespace fog::svr {

svr_base::svr_base(const std::string& name): _name(name), _stop(false) {
    this->_logger = new ::fog::log::logger(name);
    this->_logger->print("server::constructor by", this->_name);
}
svr_base::~svr_base() {
    this->_logger->print("server::destructor by", this->_name);
    delete this->_logger;
}
const std::string svr_base::name() {
    return this->_name;
}
void svr_base::stop() {
    this->_logger->print("server::stop by", this->_name);
}
void svr_base::svr_run() {
    this->_logger->print("server::svr_run by", this->_name);
}

}