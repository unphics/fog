#ifndef fog_utils_static_stringing
#define fog_utils_static_stringing

#include <iostream>
#include <queue>
#include <memory>
#include <type_traits>

namespace fog::utils::string {


// template<char... data>
// struct STR {
//     template<char... N>
//     using push_back = STR<data..., N...>;
//     template<char... N>
//     using push_front = STR<N..., data...>;
//     constexpr static char str[] = {data...};
// };

template<std::size_t N>
struct static_string {
    constexpr static_string(const char (&str)[N]) {
        for (auto i = 0; i < N; i++) {
            _data[i] = str[i];
        }
    }
    constexpr auto* data() const {
        return _data;
    }
    char _data[N];
};
/*
template<static_string s>
void foo() {
    std::cout << "foo" << std::endl;
}
template<>
void foo<"ikun">() {
    std::cout << "ikun" << std::endl;
}
template<>
void foo<"qqq">() {
    std::cout << "qqq" << std::endl;
}
template<>
void foo<"eee">() {
    std::cout << "eee" << std::endl;
}
int main1() {
    foo<"ikun">();
    foo<"qqq">();
    foo<"www">();
    foo<"eee">();

    return 0;
}
*/

}

#endif