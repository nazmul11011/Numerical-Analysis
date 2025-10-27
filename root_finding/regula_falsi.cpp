#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Define the function f(x)
double f(double x) {
    // Example: f(x) = x^3 + 3x - 3
    return 4*pow(x, 2) + 3*x - 3;
}

void regula_falsi(double l, double u, double tol = 1e-6, int max_iter = 100) {
    if (f(l) * f(u) >= 0) {
        cout << "Error: f(l) and f(u) must have opposite signs." << endl;
        return;
    }

    double c;
    int iteration = 0;

    cout << fixed << setprecision(10);
    cout << "Iter\t a\t\t b\t\t c\t\t f(c) \t\t abs(u - l)\n";

    while (fabs(u - l) >= tol) {
        c = u - (f(u) * (l - u)) / (f(l) - f(u));
        double fc = f(c);
        cout << iteration + 1 << "\t" << l << "\t" << u << "\t" << c << "\t" << fc << "\t" << fabs(u - l) << endl;

        // Check if root found
        if (fabs(fc) < tol) {
            break;
        }

        // Decide the side to repeat the steps
        if (f(l) * fc < 0) {
            u = c;
        } else {
            l = c;
        }

        iteration++;
    }

    c = u - (f(u) * (l - u)) / (f(l) - f(u));
    cout << "\nApproximate root: " << c << " after " << iteration << " iterations.\n";
    cout << "f(root) :" << f(c) << endl;
}

int main() {
    double l, u;

    // Input interval
    cout << "Enter the interval [l, u] such that f(l)*f(u) < 0:\n";
    cout << "l = ";
    cin >> l;
    cout << "u = ";
    cin >> u;

    regula_falsi(l, u);

    return 0;
}