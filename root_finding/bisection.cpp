#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Define the function f(x)
double f(double x) {
    // Example: f(x) = 4x^2 + 3x - 3
    return 4*pow(x, 2) + 3*x - 3;
}

// Bisection Method implementation
void bisection(double a, double b, double tol = 1e-6) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    double c; // Midpoint
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\t a\t\t b\t\t c\t\t f(c)\n";

    while ((b - a) >= tol) {
        c = (a + b) / 2.0;
        double fc = f(c);
        cout << iteration + 1 << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        // Check if root found
        if (fabs(fc) < tol) {
            break;
        }

        // Decide the side to repeat the steps
        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    }

    c = (a + b) / 2.0;
    cout << "\nApproximate root: " << c << " after " << iteration << " iterations.\n";
    cout << "f(root) :" << f(c) << endl;
}

int main() {
    double a, b;

    // Input interval
    cout << "Enter the interval [a, b] such that f(a)*f(b) < 0:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    bisection(a, b);

    return 0;
}