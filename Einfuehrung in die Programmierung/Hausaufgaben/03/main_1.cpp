// joshua.feld@rwth-aachen.de, 406718

#include <iostream>

using namespace std;

template <typename T1, typename T2>
double f(T1 a, T2 b) {
    return (a / b) * (b / a);
}

int main() {
    int i1 = 2, i2 = 3;
    double d = 4.0;
    cout << "f(i1, i1) = f(2, 2) = " << f(i1, i1) << endl;
    cout << "f(i1, i2) = f(2, 3) = " << f(i1, i2) << endl;
    cout << "f(i1, d) = f(2, 4.0) = " << f(i1, d) << endl;
    cout << "f(d, i1) = f(4.0, 2) = " << f(d, i1) << endl;
    cout << "f(d, d) = f(4.0, 4.0) = " << f(d, d) << endl;
    return 0;
}
