#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 1e18, MOD = 1e9 + 7, maxn = 1e6;

void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    multiset<int> s;
    for (int i = n - 1; i >= 0; --i) {
        s
    }
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
