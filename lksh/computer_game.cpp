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

const int inf = 1e8, maxn = 1e5 + 5;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int last = -1, c1 = 0, c2 = 0, k = 0;
    while (last < n - 1) {
        int mx = -1, mx_index = 0;
        for (int i = last + 1; i < n; ++i) {
            if (a[i] >= mx) {
                mx = a[i];
                mx_index = i;
            }
        }
        last = mx_index;
        if (k == 0) {
            c1 += mx;
        } else {
            c2 += mx;
        }
        k = 1 - k;
    }
    cout << c1 - c2;
    return 0;
}