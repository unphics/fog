#ifndef fog_utils_type_list
#define fog_utils_type_list

#include <stddef.h>
#include <type_traits>

namespace fog::utils::tmpl {

template<typename... T>
struct type_list {
    using type = type_list<T...>;
};

template<typename L, size_t N>
struct get_nth_type;

template<typename T, typename... Ts, size_t N>
struct get_nth_type<type_list<T, Ts...>, N> {
    using type = typename std::conditional<N == 0, T, typename get_nth_type<type_list<Ts...>, N - 1>::type>::type;
};

template<size_t N>
struct get_nth_type<type_list<>, N> {
    using type = void;
};

}

#endif