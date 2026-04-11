#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static void dfsFinish(int u, const vector<vector<int>>& g, vector<bool>& seen,
                      vector<int>& order) {
    seen[u] = true;
    for (int v : g[u]) {
        if (!seen[v]) {
            dfsFinish(v, g, seen, order);
        }
    }
    order.push_back(u);
}

static void dfsCollect(int u, const vector<vector<int>>& gr, vector<bool>& seen,
                       vector<int>& verts) {
    seen[u] = true;
    verts.push_back(u);
    for (int v : gr[u]) {
        if (!seen[v]) {
            dfsCollect(v, gr, seen, verts);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> g(n);
    vector<vector<int>> gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    vector<bool> seen1(n, false);
    vector<int> finish;
    finish.reserve(n);
    for (int i = 0; i < n; i++) {
        if (!seen1[i]) {
            dfsFinish(i, g, seen1, finish);
        }
    }

    vector<int> sccId(n, -1);
    vector<bool> seen2(n, false);
    for (int k = n - 1; k >= 0; k--) {
        int u = finish[k];
        if (seen2[u]) {
            continue;
        }
        vector<int> comp;
        dfsCollect(u, gr, seen2, comp);
        int id = *min_element(comp.begin(), comp.end());
        for (int v : comp) {
            sccId[v] = id;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sccId[i] << '\n';
    }
    return 0;
}
