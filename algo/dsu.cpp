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

const int inf = 1e7, maxn = 1e5;

struct DSU {
    int n;
    vector<int> p, s;
    int leader(int v) {
        if (v == p[v]) {
            return v;
        } else {
            return p[v] = leader(p[v]);
        }
    }
    void unite(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (a != b) {
            if (s[a] < s[b]) {
                swap(a, b);
            }
            p[b] = a;
            s[a] += s[b];
        }
    }
    void init(int n) {
        p.resize(n + 1);
        s.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            s[i] = 1;
        }
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}