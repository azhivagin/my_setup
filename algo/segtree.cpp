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

int n;
vector<long long> t;

void build(const vector<long long> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

long long get(const vector<long long> &a, int v, int tl, int tr, int l, int r) {
    if (max(tl, l) > min(tr, r)) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return get(a, v * 2, tl, tm, l, r) + get(a, v * 2 + 1, tm + 1, tr, l, r);
}

void update(const vector<long long> &a, int v, int tl, int tr, int i) {
    if (tl == tr) {
        t[v] = a[i];
    } else {
        int tm = (tl + tr) / 2;
        if (i <= tm) {
            update(a, v * 2, tl, tm, i);
        } else {
            update(a, v * 2 + 1, tm + 1, tr, i);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

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