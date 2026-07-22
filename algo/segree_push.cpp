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

vector<long long> a(maxn), add(maxn * 4), _set(maxn * 4, inf), t(maxn * 4);

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
}

long long get_point(int v) {
    if (_set[v] == inf) {
        return t[v] + add[v];
    } else {
        return _set[v] + add[v];
    }
}

void update_point(int v) { t[v] = min(get_point(v * 2), get_point(v * 2 + 1)); }

void push(int v) {
    if (_set[v] == inf) {
        t[v] += add[v];
        if (_set[v * 2] == inf) {
            add[v * 2] += add[v];
        } else {
            _set[v * 2] += add[v];
        }
        if (_set[v * 2 + 1] == inf) {
            add[v * 2 + 1] += add[v];
        } else {
            _set[v * 2 + 1] += add[v];
        }
        add[v] = 0;
    } else {
        t[v] = _set[v];
        _set[v * 2] = _set[v * 2 + 1] = _set[v];
        add[v] = add[v * 2] = add[v * 2 + 1] = 0;
        _set[v] = inf;
    }
}

void tree_set(int v, int tl, int tr, int l, int r, long long x) {
    if (max(tl, l) > min(tr, r)) {
        return;
    } else if (l <= tl && tr <= r) {
        _set[v] = x;
        add[v] = 0;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        tree_set(v * 2, tl, tm, l, r, x);
        tree_set(v * 2 + 1, tm + 1, tr, l, r, x);
        update_point(v);
    }
}

void tree_add(int v, int tl, int tr, int l, int r, long long x) {
    if (max(tl, l) > min(tr, r)) {
        return;
    } else if (l <= tl && tr <= r) {
        add[v] += x;
        if (_set[v] != inf) {
            _set[v] += add[v];
            add[v] = 0;
        }
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        tree_add(v * 2, tl, tm, l, r, x);
        tree_add(v * 2 + 1, tm + 1, tr, l, r, x);
        update_point(v);
    }
}

long long tree_get(int v, int tl, int tr, int l, int r) {
    if (max(tl, l) > min(tr, r)) {
        return inf;
    } else if (l <= tl && tr <= r) {
        return get_point(v);
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        long long m1 = tree_get(v * 2, tl, tm, l, r);
        long long m2 = tree_get(v * 2 + 1, tm + 1, tr, l, r);
        long long res = min(m1, m2);
        update_point(v);
        return res;
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