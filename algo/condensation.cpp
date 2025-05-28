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

int cnt_components = 0;

void dfs1(int v, const vector<vector<int>> &g, vector<int> &order,
          vector<int> &used) {
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs1(u, g, order, used);
        }
    }
    order.push_back(v);
}

void dfs2(int v, const vector<vector<int>> &t, vector<int> &components) {
    components[v] = cnt_components;
    for (int u : t[v]) {
        if (components[u] == -1) {
            dfs2(u, t, components);
        }
    }
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
    vector<vector<int>> g(n), t(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        t[v - 1].push_back(u - 1);
    }
    vector<int> used(n), order;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i, g, order, used);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> components(n, -1);
    for (int v : order) {
        if (components[v] == -1) {
            dfs2(v, t, components);
            cnt_components++;
        }
    }
    return 0;
}