#include <bits/stdc++.h>
using namespace std;

// Function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

int main() {
    double a, b; // limits of integration
    int n;       // number of sub-intervals (must be multiple of 3)

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, multiple of 3): ";
    cin >> n;

    if (n % 3 != 0) {
        cout << "Number of intervals must be a multiple of 3!" << endl;
        return 0;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    double result = (3 * h / 8) * sum;
    cout << fixed << setprecision(6);
    cout << "Approximate integral = " << result << endl;

    return 0;
}
