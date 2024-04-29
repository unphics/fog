#ifndef fog_actor_def
#define fog_actor_def

#include <tuple>

#include "actor/actor.hh"
#include "actor/session.hh"
#include "actor/tick.hh"


#include "utils/type_list.hh"

namespace fog::actor {

enum class def {
    actor,
    session,
    tick,
};

using types = ::fog::utils::tmpl::type_list<session, tick>;

template<def d>
using def_class_t = ::fog::utils::tmpl::get_nth_type<types, ((int)d - 1)>::type;;

}

#endif