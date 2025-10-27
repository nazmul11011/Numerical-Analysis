#include <bits/stdc++.h>
using namespace std;

// Function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

int main() {
    double a, b; // limits of integration
    int n;       // number of sub-intervals (must be even)

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, even): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Number of intervals must be even!" << endl;
        return 0;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double result = (h / 3) * sum;
    cout << fixed << setprecision(6);
    cout << "Approximate integral = " << result << endl;

    return 0;
}
