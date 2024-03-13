#ifndef fog_center_center
#define fog_center_center

/**
 * @brief center server
 */

#include "actor/session.hh"

namespace fog::center {

class center: public actor::session {
public:
    virtual void start() override {

        this->session::start();
    }
};

}

#endif