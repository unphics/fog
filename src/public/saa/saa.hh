#ifndef fog_saa_saa
#define fog_saa_saa

#include "essential.hh"

#include "saa/linear_list.hh"
#include "saa/singly_linked_list.hh"

#include <cstring>

namespace fog::saa {


void saa() {
    print("===== SAA begin =====");
    linear_list::linear_list();
    linked_list::test_singly_linked_list();
    
    // https://www.bilibili.com/video/BV1kW4y1E7Qi?p=21&spm_id_from=pageDriver&vd_source=2996cb3dd8788164f70bbabbf73b60b6
}

}

#endif