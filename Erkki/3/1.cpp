#include <cmath>
#include <iostream>

using namespace std;

void sekunnit_ajaksi(int s_tot, int& h, int& m, int& s) {
    h = floor((s_tot / 60) / 60);
    m = floor((s_tot / 60) - (h * 60));
    s = floor(s_tot - ((h * 60 * 60) + (m * 60)));
}

int main() {
    int s_tot = 10000;
    int h, m, s;
    sekunnit_ajaksi(s_tot, h, m, s);
    cout << s_tot << " sekuntia on " << h << " tuntia " << m << " minuuttia "
         << s << " sekuntia.";
    return 0;
}
