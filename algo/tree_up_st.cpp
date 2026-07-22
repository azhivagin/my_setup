#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
// #define int long long

using namespace std;

const int inf = 1e9;
const int MOD = 16714589;
const int lg = 25;
int t = 0;

vector<vector<int>> g, up;
vector<int> tin, tout, first, euler, depth;

void dfs(int v, int p, int dep) {
    first[v] = euler.size();
    euler.push_back(v);
    depth.push_back(dep);
    tin[v] = t++;
    if (v > 0) {
        up[v][0] = p;
        for (int k = 1; k < lg; ++k) {
            up[v][k] = up[up[v][k - 1]][k - 1];
        }
    }
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, dep + 1);
            euler.push_back(v);
            depth.push_back(dep);
        }
    }
    tout[v] = t;
}

bool ancestor(int p, int v) { return tin[p] <= tin[v] && tin[v] < tout[p]; }

void solve() {
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    up.assign(n, vector<int>(lg));
    first.assign(n, 0);
    tin.assign(n, 0);
    tout.assign(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int k = 0; k < lg; ++k) {
        up[0][k] = 0;
    }
    dfs(0, -1, 0);
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (!ancestor(u, v)) {
            cout << up[u][0] + 1 << "\n";
        } else {
            for (int k = lg - 1; k >= 0; --k) {
                if (!ancestor(up[v][k], u)) {
                    v = up[v][k];
                }
            }
            cout << v + 1 << "\n";
        }
    }
    // int sz = (int)depth.size();
    // vector<vector<pair<int, int>>> f(lg, vector<pair<int, int>>(sz));
    // for (int i = 0; i < sz; ++i) {
    //     f[0][i] = {depth[i], euler[i]};
    // }
    // for (int k = 0; k < lg - 1; ++k) {
    //     for (int i = 0; i + (1 << (k + 1)) <= sz; ++i) {
    //         f[k + 1][i] = min(f[k][i], f[k][i + (1 << k)]);
    //     }
    // }
    // int m;
    // cin >> m;
    // while (m--) {
    //     int u, v;
    //     cin >> u >> v;
    //     --u;
    //     --v;
    //     int l = first[u], r = first[v];
    //     if (l > r) {
    //         swap(l, r);
    //     }
    //     ++r;
    //     int k = __lg(r - l);
    //     pair<int, int> best = min(f[k][l], f[k][r - (1 << k)]);
    //     if (best.second == u) {
    //         best.second = v;
    //     }
    //     cout << best.second + 1 << "\n";
    // }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    bool multi = false;
    if (multi) {
        cin >> tests;
    }
    while (tests--) {
        solve();
    }
    return 0;
}
