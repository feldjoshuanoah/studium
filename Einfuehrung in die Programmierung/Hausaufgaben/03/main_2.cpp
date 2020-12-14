// joshua.feld@rwth-aachen.de

#include <iostream>

using namespace std;

int main() {
    short s = 0;
    int i = 0;
    unsigned int ui = 0;
    long l = 0;
    long long ll = 0;
    float f = 0.0;
    double d = 0.0;
    long double ld = 0.0;
    bool b = false;
    char c = 'a';

    cout << "Size of short is " << sizeof s << "B" << endl;
    cout << "Size of int is " << sizeof i << "B" << endl;
    cout << "Size of unsigned int is " << sizeof ui << "B" << endl;
    cout << "Size of long is " << sizeof l << "B" << endl;
    cout << "Size of long long is " << sizeof ll << "B" << endl;
    cout << "Size of float is " << sizeof f << "B" << endl;
    cout << "Size of double is " << sizeof d << "B" << endl;
    cout << "Size of long double is " << sizeof ld << "B" << endl;
    cout << "Size of bool is " << sizeof b << "B" << endl;
    cout << "Size of char is " << sizeof c << "B" << endl;

    int& j = i;
    int* k = &i;

    cout << "Address of i (variable) is " << &i << endl;
    cout << "Address of j (alias) is " << &j << endl;
    cout << "Address of k (pointer) is " << &k << endl;
    cout << "Value of k is " << k << endl;
    cout << "Dereferenced value of k is " << *k << endl;

    return 0;
}
