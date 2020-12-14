// joshua.feld@rwth-aachen.de, 406718

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> read_matrix_from_file(string p) {
    ifstream f(p);
    int m = 0, n = 0;
    f >> m;
    f >> n;
    vector<vector<int>> M(m);
    for (int i = 0; i < m; i++) {
        vector<int> v(n, 0);
        for (int j = 0; j < n; j++) {
            f >> v[j];
        }
        M[i] = v;
    }
    return M;
}

vector<int> read_vector_from_file(string p) {
    ifstream f(p);
    int n = 0;
    f >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        f >> v[i];
    }
    return v;
}

void multiply(vector<vector<int>> M, vector<int> v, vector<int>& x) {
    const int m = M.size();
    vector<int> Mv(m, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v.size(); j++) {
            Mv[i] += M[i][j] * v[j];
        }
    }
    x = Mv;
}

void multiply(vector<int> v, vector<int> w, int& x) {
    int n = v.size();
    int vw = 0;
    for (int i = 0; i < n; i++) {
        vw += v[i] * w[i];
    }
    x = vw;
}

int multiply(vector<int> v, vector<vector<int>> M, vector<int> x) {
    vector<int> Mx(x.size(), 0);
    multiply(M, x, Mx);
    int vMx = 0;
    multiply(v, Mx, vMx);
    return vMx;
}

int main(int argc, char** argv) {
    if (argc == 4) {
        cout << multiply(
            read_vector_from_file(argv[1]),
            read_matrix_from_file(argv[2]),
            read_vector_from_file(argv[3])
        ) << endl;
    }
    return 0;
}
