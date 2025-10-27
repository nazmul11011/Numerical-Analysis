#include <bits/stdc++.h>
using namespace std;

// Function to perform Gauss-Jordan Elimination
void gaussJordan(vector<vector<double>> a, int n) {
    for (int i = 0; i < n; i++) {
        // Partial Pivoting (to handle zero or small pivots)
        int pivot = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[pivot][i]))
                pivot = k;
        }
        swap(a[i], a[pivot]);

        // Make the diagonal element 1
        double diag = a[i][i];
        for (int j = 0; j <= n; j++)
            a[i][j] /= diag;

        // Make all other elements in column i zero
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Print the solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << a[i][n] << endl;
}

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));
    cout << "Enter augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    gaussJordan(a, n);
    return 0;
}
