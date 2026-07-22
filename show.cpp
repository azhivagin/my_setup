#include <stdexcept>
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int inf = 2e9;
const int MOD = 1e9 + 7;
const int maxn = 1e9 + 1, lg = 19, c = 2155;

struct Node {
    int i;
    int a, b;
};

// skebob
void solve() {
    int n;
    cin >> n;
    vector<vector<Node>> poc(n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --c;
        poc[c].push_back({i, a, b});
    }
    for (int i = 0; i < n; ++i) {
        sort(poc[i].begin(), poc[i].end(), [](Node left, Node right){
            if (left.b == right.b) {
                return left.a > right.b;
            }
            return left.b < right.b;
        });
    }
    sort(poc.begin(), poc.end(),
         [](Node left, Node right) { return left.x > right.x; });
    cout << poc[0].i + 1 << " " << poc[1].i + 1 << "\n";
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
