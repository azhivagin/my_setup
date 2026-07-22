#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 1e18;
const int MOD = 777777777;
const int maxn = 1e5 + 1, lg = 19;

// skebob
void solve() {
    
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
