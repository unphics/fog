#ifndef fog_center_center_svr
#define fog_center_center_svr

#include "svr/svr_base.hh"

namespace fog::gate {class gate_svr;}
namespace fog::login {class login_svr;}

namespace fog::center {

class center_svr: public svr::svr_base {
public:
    center_svr(std::string name);
    virtual ~center_svr();
    void tick();
    virtual void svr_run() override;
    login::login_svr* login();
private:
    void run_gate();
    void run_login();
    gate::gate_svr* _gate;
    login::login_svr* _login;
};

}


#endif