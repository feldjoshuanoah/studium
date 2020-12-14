// joshua.feld@rwth-aachen.de, 406718

#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

template<class T>
void to_bin(T v) {
    union {
        T value;
        unsigned char bytes[sizeof(T)];
    };
    memset(&bytes, 0, sizeof(T));
    value = v;
    // assumes little endian machine
    for (size_t i = sizeof(T); i > 0; i--) {
        unsigned char pot=128;
        for (int j = 7; j >= 0; j--, pot /= 2) {
            if (bytes[i-1] & pot) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
    const int is[] = {
        -9, 17, numeric_limits<int>::max(), numeric_limits<int>::max() + 1
    };
    for (const int i : is) {
        cout << "to_bin(" << i << ") = ";
        to_bin(i);
    }
    const float f = 3.25, g = -1.5;
    cout << "to_bin(3.25) = "; to_bin(f);
    cout << "to_bin(-1.5) = "; to_bin(g);
    return 0;
}
