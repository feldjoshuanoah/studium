// joshua.feld@rwth-aachen.de, 406718

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_list_from_file(string p) {
    ifstream f(p);
    vector<int> l;
    while (true) {
        int x;
        f >> x;
        l.push_back(x);
        if (f.eof()) {
            break;
        }
    }
    auto a = l.begin();
    return l;
}

int binary_search(int z, vector<int>::iterator a, vector<int>::iterator b, vector<int>::iterator &x) {
    int d = distance(a, b) + 1;
    advance(a, d / 2);
    if (*a == z) {
        x = a;
        return 1;
    } else if (*a < z) {
        return binary_search(z, a, b, x) + 1;
    }
    advance(a, -d / 2);
    advance(b, -d / 2);
    return binary_search(z, a, b, x) + 1;
}

int main(int argc, char* argv[]) {
    vector<int> l = read_list_from_file(argv[2]);
    vector<int>::iterator x;
    cout << binary_search(atoi(argv[1]), l.begin(), l.end(), x) << std::endl;

    cout << "predecessor of z is " << *(prev(x)) << endl;
    cout << "z is " << *x << endl;
    cout << "successor of z is " << *(next(x)) << endl;
}
