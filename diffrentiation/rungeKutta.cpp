#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y; // Example: dy/dx = x + y
}

int main() {
    double x0, y0, xn, h, x, y, k1, k2, k3, k4;
    cout << "Enter initial x0, y0: ";
    cin >> x0 >> y0;
    cout << "Enter final x (xn): ";
    cin >> xn;
    cout << "Enter step size (h): ";
    cin >> h;

    x = x0;
    y = y0;

    cout << fixed << setprecision(5);
    cout << "\nRunge-Kutta 4th Order Method\n";
    cout << "x\t\ty\n";

    while (x < xn + 1e-9) {
        cout << x << "\t" << y << "\n";

        k1 = f(x, y);
        k2 = f(x + h / 2.0, y + (h / 2.0) * k1);
        k3 = f(x + h / 2.0, y + (h / 2.0) * k2);
        k4 = f(x + h, y + h * k3);

        y = y + (h / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
        x += h; 
    }

    cout << "\nApproximate value of y at x = " << xn << " is " << y << endl;
    return 0;
}
