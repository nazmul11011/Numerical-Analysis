#include <bits/stdc++.h>
using namespace std;

double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double xp) {
    int n = x.size();
    double yp = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += term;
    }

    return yp;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter data points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double xp;
    cout << "Enter value of x to interpolate: ";
    cin >> xp;

    double yp = lagrangeInterpolation(x, y, xp);

    cout << fixed << setprecision(6);
    cout << "Interpolated value at x = " << xp << " is " << yp << "\n";

    return 0;
}
