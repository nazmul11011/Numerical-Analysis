#include <bits/stdc++.h>
using namespace std;

// Function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

int main() {
    double a, b; // integration limits
    int n;       // number of sub-intervals

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    double h = (b - a) / n; // step size
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    double result = (h / 2) * sum;
    cout << fixed << setprecision(6);
    cout << "Approximate integral = " << result << endl;

    return 0;
}
