#include <iostream>
#include <vector>
using namespace std;

const int VECTOR_LEN = 10;
const int K = 4;  // values in {0, 1, 2, 3}

void countingSortByPos(vector<vector<int>>& A, int pos) {
    int n = A.size();
    vector<int> C(K, 0);
    vector<vector<int>> B(n, vector<int>(VECTOR_LEN));

    for (int i = 0; i < n; i++) {
        C[A[i][pos]]++;
    }
    for (int v = 1; v < K; v++) {
        C[v] += C[v - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = A[i][pos];
        B[C[x] - 1] = A[i];
        C[x]--;
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void radixSort(vector<vector<int>>& A) {
    for (int pos = VECTOR_LEN - 1; pos >= 0; pos--) {
        countingSortByPos(A, pos);
    }
}

int main() {
    int m;
    cin >> m;
    vector<vector<int>> A(m, vector<int>(VECTOR_LEN));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < VECTOR_LEN; j++) {
            cin >> A[i][j];
        }
    }
    radixSort(A);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < VECTOR_LEN; j++) {
            cout << A[i][j] << ";";
        }
        cout << "\n";
    }
    return 0;
}
