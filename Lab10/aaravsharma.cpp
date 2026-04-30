#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static string printOptimalParens(const vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        return "A" + to_string(i);
    }
    int k = s[i][j];
    return "(" + printOptimalParens(s, i, k) + printOptimalParens(s, k + 1, j) + ")";
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<long long>> m(n, vector<long long>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            m[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                long long cost =
                    m[i][k] + m[k + 1][j] + (long long)p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[0][n - 1] << "\n";
    cout << printOptimalParens(s, 0, n - 1) << "\n";
    return 0;
}
