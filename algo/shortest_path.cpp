#include <algorithm>
#include <cctype>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #define int long long

using namespace std;

int maxn = 1e5, inf = 1e9;

vector<int> bfs(int s, const vector<vector<int>> &g, int n) {
    queue<int> q;
    q.push(s);
    vector<int> d(n, -1), p(n);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (d[u] == -1) {
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    return d;
}

vector<int> dijkstra(int s, int n, const vector<vector<pair<int, int>>> &g) {
    vector<int> d(n, inf);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    q.push({0, s});
    while (!q.empty()) {
        auto [cur_d, v] = q.top();
        q.pop();
        if (cur_d > d[v]) continue;
        for (auto [u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({d[u], u});
            }
        }
    }
    return d;
}

vector<vector<int>> floyd(int n, const vector<vector<int>> &g) {
    vector<vector<int>> d(n, vector<int>(n));
    // d = g
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < inf && d[k][j] < inf) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    return d;
}

struct Edge {
    int from, to, w;
};

vector<int> ford(int s, int n, const vector<Edge> &g) {
    vector<int> d(n, inf);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto [from, to, w] : g) {
            if (d[from] < inf) {
                d[to] = min(d[to], d[from] + w);
            }
        }
    }
    return d;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}