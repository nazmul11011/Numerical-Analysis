#include <bits/stdc++.h>
using namespace std;

// Function to perform Gaussian Elimination with Partial Pivoting
void gaussianEliminationPivot(vector<vector<double>> a, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Partial Pivoting: find the row with maximum element in column i
        int pivot = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > fabs(a[pivot][i]))
                pivot = k;
        }

        // Swap the rows if needed
        if (pivot != i)
            swap(a[i], a[pivot]);

        // Eliminate elements below pivot
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++)
                a[k][j] -= factor * a[i][j];
        }
    }

    // Back Substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << x[i] << endl;
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

    gaussianEliminationPivot(a, n);
    return 0;
}
