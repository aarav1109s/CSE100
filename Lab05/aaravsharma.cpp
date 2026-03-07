#include <iostream>
#include <vector>
using namespace std;

void countingSortByPos(vector<vector<int>> &A, int pos) {
    int n = A.size();
    int k = 4; // values 0..3

    vector<int> C(k, 0);
    vector<vector<int>> B(n, vector<int>(10));

    // Count occurrences
    for (int i = 0; i < n; i++) {
        C[A[i][pos]]++;
    }

    // Prefix sums
    for (int v = 1; v < k; v++) {
        C[v] += C[v - 1];
    }

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        int x = A[i][pos];
        B[C[x] - 1] = A[i];
        C[x]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void radixSort(vector<vector<int>> &A) {
    for (int pos = 9; pos >= 0; pos--) {
        countingSortByPos(A, pos);
    }
}

int main() {
    int m;
    cin >> m;

    vector<vector<int>> A(m, vector<int>(10));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }

    radixSort(A);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j] << ";";
        }
        cout << endl;
    }

    return 0;
}