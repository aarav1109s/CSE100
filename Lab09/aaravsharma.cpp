#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
// MinGW g++ -std=c++11 does not declare `_fileno` (strict ANSI); link against CRT anyway.
extern "C" int _fileno(::FILE*);
#endif
using namespace std;

struct Edge {
    int u;
    int v;
    long long w;
};

int main() {
#ifdef _WIN32
    // Autograder `diff` expects Unix (LF) line endings; avoid CRLF translation.
    (void)_setmode(_fileno(stdout), _O_BINARY);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<Edge> edges;
    edges.reserve(static_cast<size_t>(m));
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    const long long INF = numeric_limits<long long>::max() / 4;
    vector<long long> dist(static_cast<size_t>(n), INF);
    dist[0] = 0;

    for (int it = 0; it < n - 1; it++) {
        for (const Edge& e : edges) {
            if (dist[static_cast<size_t>(e.u)] == INF) {
                continue;
            }
            long long nd = dist[static_cast<size_t>(e.u)] + e.w;
            if (nd < dist[static_cast<size_t>(e.v)]) {
                dist[static_cast<size_t>(e.v)] = nd;
            }
        }
    }

    bool negCycleReachable = false;
    for (const Edge& e : edges) {
        if (dist[static_cast<size_t>(e.u)] == INF) {
            continue;
        }
        long long nd = dist[static_cast<size_t>(e.u)] + e.w;
        if (nd < dist[static_cast<size_t>(e.v)]) {
            negCycleReachable = true;
            break;
        }
    }

    if (negCycleReachable) {
        cout << "FALSE\n";
        return 0;
    }

    cout << "TRUE\n";
    for (int i = 0; i < n; i++) {
        if (dist[static_cast<size_t>(i)] == INF) {
            cout << "INFINITY\n";
        } else {
            cout << dist[static_cast<size_t>(i)] << '\n';
        }
    }
    return 0;
}
