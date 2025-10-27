#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Define the function f(x)
double f(double x) {
    // Example: f(x) = 4x^2 + 3x - 3
    return 4*pow(x, 2) + 3*x - 3;
}
double df(double x) {
    // Example: f(x) = 4x^2 + 3x - 3
    return 8*x + 3;
}

void newton(double x0, double tol = 1e-6, int max_it=100) {
    double x1;
    int it=1;
    cout << fixed << setprecision(6);
    cout << "Iter\t X0\t\t X1\t\t f(x1)\n";
    while(it<max_it){
        x1=x0-f(x0)/df(x0);
        cout << it << "\t" << x0 << "\t" << x1 << "\t" << f(x1) << endl;
        if(fabs(x1-x0)<tol) break;
        x0=x1;it++;
    }
    cout << "Root "<<x1<<endl;
}

int main() {
    double x0=1;

    newton(x0);

    return 0;
}