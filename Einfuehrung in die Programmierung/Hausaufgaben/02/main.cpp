// joshua.feld@rwth-aachen.de, 406718

#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream in("matrix.txt"); // input file
    ofstream out("matrix_abs.txt"); // output file
    int m = 0, n = 0; // m is the amount of rows, n the amount of columns
    in >> m; // read m from the input file
    in >> n; // read n from the input file
    for (; m > 0; m--) {
        vector<int> x(n, 0); // vector representing the current row
        for (int i = 0; i < n; i++) {
            in >> x[i]; // reads the entries of the row vector
        }
        for (int i = 0; i < n; i++) {
            // writes the absolute value of each vector entry to the output
            out << abs(x[i]) << " ";
        }
        out << "\n"; // adds a new line for the next row
    }
}
