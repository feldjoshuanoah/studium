// joshua.feld@rwth-aachen.de, 406718

#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream input("matrix.txt"); // input file
    ofstream output("matrix_abs.txt"); // output file
    int m = 0, n = 0; // m is the amount of rows, n the amount of columns
    input >> m; // read m from the input file
    input >> n; // read n from the input file
    for (; m > 0; m--) {
        vector<int> x(n, 0); // vector representing the current row
        for (int i = 0; i < n; i++) {
            input >> x[i]; // reads the entries of the row vector
        }
        for (int i = 0; i < n; i++) {
            // writes the absolute value of each vector entry to the output
            output << abs(x[i]) << " ";
        }
        output << "\n"; // adds a new line for the next row
    }
}
