#include <cassert>
#include <iostream>
#include "../src/roman.hpp"

int main () {
    Roman p;

    Roman q("MMMDCCCLXXXVIII");
    Roman r("I");
     p.SetRoman("VII");
    
    assert(q.GetInt()== 3888);
    assert(r.GetInt()== 1);

    Roman m(3999);
    Roman a(1);
    assert(m.GetRoman()== "MMMCMXCIX");
    assert(a.GetRoman()== "I");
}