#include <cassert>
#include <cmath>
#include "../src/roman.hpp"

int main () {
        Roman p("MMMDCCCLXXXVIII");   // 3888
        Roman q("CXI");       // 111

        p.IncreaseWith(q);

        assert(p.GetInt() == 3999);
        assert(p.GetRoman() == "MMMCMXCIX");

	return 0;
}