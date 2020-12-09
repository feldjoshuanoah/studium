// joshua.feld@rwth-aachen.de
#include <iostream>
#include <cmath>
#include <random>

namespace model {
    double f(double x) {
        if (x <= -2) {
            return 12;
        } else if (x > -2 && x <= 0) {
            return -3 * x * x - 12 * x;
        } else if (x > 0 && x <= 2) {
            return 2 * x;
        }
        return std::cos(M_PI * x) + 3;
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
        return std::sin(M_PI * x) + 3 * x;
    }
}

double exact() {
    double F_ges[] = {
            model::F_1(-2) - model::F_1(-4), model::F_2(0) - model::F_2(-2),
            model::F_3(2) - model::F_3(0), model::F_4(4) - model::F_4(2)
    };
    double res = 0;
    for (double F_i : F_ges) {
        res += F_i;
    }
    return res;
}

double monteCarlo(int n) {
    std::default_random_engine engine;
    std::uniform_real_distribution<double> xDist(-4, 4);
    std::uniform_real_distribution<double> yDist(0, 16);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (yDist(engine) <= model::f(xDist(engine))) {
            m++;
        }
    }
    return ((double) m) / ((double) n) * 128;
}

double rectangles(int n) {
    double res = 0;
    double w = 8.0 / n;
    for (int i = 0; i < n; i++) {
        res += w * model::f(-4 + w / 2 + i * w);
    }
    return res;
}

double error(double A_tilde) {
    double A = exact();
    return std::abs((A_tilde - A) / A);
}

int main() {
    bool mon, rec;
    std::cout << "Integral mit Monte Carlo Methode berechnen? (0: N, 1: Y):"; std::cin >> mon;
    std::cout << "Integral mit Rechtecksverfahren berechnen? (0: N, 1: Y):"; std::cin >> rec;
    std::cout << std::endl;
    int n[] = { 10, 100, 1000, 10000, 100000 };
    double monteCarloResults[5], rectanglesResults[5];
    if (mon) {
        for (int i = 0; i < 5; i++) {
            monteCarloResults[i] = monteCarlo(n[i]);
        }
        std::cout << "Berechnung mit Monte Carlo Methode abgeschlossen" << std::endl;
    }
    if (rec) {
        for (int i = 0; i < 5; i++) {
            rectanglesResults[i] = rectangles(n[i]);
        }
        std::cout << "Berechnung mit Rechtecksverfahren abgeschlossen" << std::endl;
    }

    std::cout << "n\tSYMB\t";
    if (mon) {
        std::cout << "MC\tMC(err)\t";
    }
    if (rec) {
        std::cout << "RV\tRV(err)";
    }
    std::cout << std::endl;
    std::cout.precision(3);
    double symb = exact();
    for (int i = 0; i < 5; i++) {
        double mc = monteCarloResults[i];
        double rv = rectanglesResults[i];
        std::cout << n[i] << "\t" << symb << "\t";
        if (mon) {
            std::cout << mc << "\t" << error(mc) << "\t";
        }
        if (rec) {
            std::cout << rv << "\t" << error(rv);
        }
        std::cout << std::endl;
    }

    return 0;
}
