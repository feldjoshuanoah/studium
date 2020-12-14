// joshua.feld@rwth-aachen.de

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int pow(int b, int e) {
    if (e == 0) {
        return 1;
    }
    return b * pow(b, e - 1);
}

void dec_to_bin(unsigned int z) {
    const unsigned int n = ceil(log(z + 1) / log(2));
    /*
     * For z = 0 and z = 4294967295 the algorithm doesn't work correctly. To
     * fix this I took the easy way out and simply printed the binary
     * representation manually.
     */
    cout << "Binärzahl: ";
    if (z == 0) {
        cout << z;
    } else if (z == numeric_limits<unsigned int>::max()) {
        cout << "11111111 11111111 11111111 11111111";
    } else {
        for (int i = n - 1; i >= 0; i--) {
            const unsigned int bit_value = pow(2, i);
            cout << z / bit_value;
            z = z % bit_value;
            if (i % 8 == 0 && i != 0) {
                cout << " ";
            }
        }
    }
    cout << endl;
}

void bin_to_dec(int n, bool bits[]) {
    unsigned int z = 0;
    for (int i = 0; i < n; i++) {
        if (bits[i]) {
            z += pow(2, n - 1 - i);
        }
    }
    cout << "Dezimalzahl: " << z << endl;
}

int main() {
    bool b;
    cout << "Wähle 0 für dec_to_bin, 1 für bin_to_dec: ";
    cin >> b;
    if (b) {
        int n;
        cout << "Anzahl der Bits: ";
        cin >> n;
        bool bits[n];
        for (int i = 0; i < n; i++) {
            cout << (i + 1) << ". Bit: ";
            cin >> bits[i];
        }
        bin_to_dec(n, bits);
    } else {
        unsigned int z;
        cout << "Dezimalzahl: ";
        cin >> z;
        dec_to_bin(z);
    }
    return 0;
}
