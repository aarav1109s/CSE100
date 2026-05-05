#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef _WIN32
    // Match Unix LF so bash `diff` against testfiles/o* passes on Windows.
    _setmode(1, _O_BINARY);
#endif

    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    const int r = 0;
    const long long INF = (long long)INT_MAX;
    vector<long long> key(V, INF);
    vector<int> parent(V, -1);
    vector<char> inMST(V, 0);

    key[r] = 0;
    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push({0, r});

    int count = 0;
    while (count < V && !Q.empty()) {
        long long d = Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if (inMST[u] || d != key[u]) {
            continue;
        }

        inMST[u] = 1;
        count++;

        for (const auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && (long long)w < key[v]) {
                key[v] = w;
                parent[v] = u;
                Q.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < V; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}
