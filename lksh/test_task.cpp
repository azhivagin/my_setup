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

const int inf = 1e8;

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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    int v = 0;
    vector<int> dv = bfs(v, g, n);
    int u, min_path = inf;
    for (int i = 1; i < n; ++i) {
        if (dv[i] < min_path) {
            u = i;
            min_path = dv[i];
        }
    }
    int w;
    min_path = inf;
    for (int i = 1; i < n; ++i) {
        if (i != u && dv[i] < min_path) {
            w = i;
            min_path = dv[i];
        }
    }
    cout << v + 1 << " " << u + 1 << " " << w + 1;
    return 0;
}