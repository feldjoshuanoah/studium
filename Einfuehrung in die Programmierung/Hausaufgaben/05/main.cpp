// joshua.feld@rwth-aachen.de, 406718

#include <iostream>
#include <cmath>
#include <random>

using namespace std;

namespace model {
    double f(double x) {
        if (x <= -2) {
            return 12;
        } else if (x > -2 && x <= 0) {
            return -3 * x * x - 12 * x;
        } else if (x > 0 && x <= 2) {
            return 2 * x;
        }
        return cos(M_PI * x) + 3;
    }

    double F_1(double x) {
        return 12 * x;
    }

    double F_2(double x) {
        return -(x * x * x) - 6 * x * x;
    }

    double F_3(double x) {
        return x * x;
    }

    double F_4(double x) {
        return sin(M_PI * x) + 3 * x;
    }
}

double exact() {
    const double F_ges[] = {
            model::F_1(-2) - model::F_1(-4), model::F_2(0) - model::F_2(-2),
            model::F_3(2) - model::F_3(0), model::F_4(4) - model::F_4(2)
    };
    double res = 0;
    for (const double F_i : F_ges) {
        res += F_i;
    }
    return res;
}

double monteCarlo(int n) {
    const default_random_engine e;
    const uniform_real_distribution<double> x_dist(-4, 4);
    const uniform_real_distribution<double> y_dist(0, 16);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (y_dist(e) <= model::f(x_dist(e))) {
            m++;
        }
    }
    return ((double) m) / ((double) n) * 128;
}

double rectangles(int n) {
    double res = 0;
    const double w = 8.0 / n;
    for (int i = 0; i < n; i++) {
        res += w * model::f(-4 + w / 2 + i * w);
    }
    return res;
}

double error(double A_tilde) {
    const double A = exact();
    return abs((A_tilde - A) / A);
}

int main() {
    bool do_m, do_r;
    cout << "Integral mit Monte Carlo Methode berechnen? (0: N, 1: Y):";
    cin >> do_m;
    cout << "Integral mit Rechtecksverfahren berechnen? (0: N, 1: Y):";
    cin >> do_r;
    cout << endl;
    const int n[] = { 10, 100, 1000, 10000, 100000 };
    double res_mc[5], res_rv[5];
    if (do_m) {
        for (int i = 0; i < 5; i++) {
            res_mc[i] = monteCarlo(n[i]);
        }
        cout << "Berechnung mit Monte Carlo Methode abgeschlossen" << endl;
    }
    if (do_r) {
        for (int i = 0; i < 5; i++) {
            res_rv[i] = rectangles(n[i]);
        }
        cout << "Berechnung mit Rechtecksverfahren abgeschlossen" << endl;
    }

    cout << "n\tSYMB\t";
    if (do_m) {
        cout << "MC\tMC(err)\t";
    }
    if (do_r) {
        cout << "RV\tRV(err)";
    }
    cout << endl;
    cout.precision(3);
    const double symb = exact();
    for (int i = 0; i < 5; i++) {
        const double mc = res_mc[i];
        const double rv = res_rv[i];
        cout << n[i] << "\t" << symb << "\t";
        if (do_m) {
            cout << mc << "\t" << error(mc) << "\t";
        }
        if (do_r) {
            cout << rv << "\t" << error(rv);
        }
        cout << endl;
    }

    return 0;
}
