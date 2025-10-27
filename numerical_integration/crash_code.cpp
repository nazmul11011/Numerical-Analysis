#include <bits/stdc++.h>
using namespace std;

// Function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++)
        sum += 2 * f(a + i * h);
    return (h / 2) * sum;
}

// Simpson’s 1/3 Rule
double simpson_one_third(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Simpson’s 1/3 Rule requires even n.\n";
        return NAN;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 4 * f(a + i * h);
    }
    return (h / 3) * sum;
}

// Simpson’s 3/8 Rule
double simpson_three_eighth(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "Simpson’s 3/8 Rule requires n to be multiple of 3.\n";
        return NAN;
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2 * f(a + i * h);
        else
            sum += 3 * f(a + i * h);
    }
    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;

    cout << fixed << setprecision(6);

    double trap = trapezoidal(a, b, n);
    double simp13 = simpson_one_third(a, b, n);
    double simp38 = simpson_three_eighth(a, b, n);

    cout << "\n--- Numerical Integration Results ---\n";
    cout << "Trapezoidal Rule      : " << trap << endl;
    if (!isnan(simp13))
        cout << "Simpson’s 1/3 Rule    : " << simp13 << endl;
    if (!isnan(simp38))
        cout << "Simpson’s 3/8 Rule    : " << simp38 << endl;

    return 0;
}
