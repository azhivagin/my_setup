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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, m, t;
    cin >> n >> m >> t;
    vector<long long> a(n), b(m);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < m; ++i) {
        cin >> b[i];
    }
    long long ans = 0;
    vector<long long> dp1(n);
    dp1[0] = a[0];
    for (long long i = 1; i < n; ++i) {
        dp1[i] = dp1[i - 1] + a[i];
    }
    vector<long long> dp2(m);
    dp2[0] = b[0];
    for (long long i = 1; i < m; ++i) {
        dp2[i] = dp2[i - 1] + b[i];
    }
    long long i = 0, j = 0;
    for (; i < n;) {
        if (dp1[i] <= t) {
            ++i;
        } else {
            break;
        }
    }
    --i;
    for (; j < m;) {
        if (dp2[j] <= t) {
            ++j;
        } else {
            break;
        }
    }
    --j;
    ans += max(i, j) + 1;
    if (j > i) {
        t -= dp2[j];
        i = 0;
        for (; i < n;) {
            if (dp1[i] <= t) {
                ++i;
            } else {
                break;
            }
        }
        --i;
        ans += i + 1;
    } else {
        t -= dp1[i];
        j = 0;
        for (; j < m;) {
            if (dp2[j] <= t) {
                ++j;
            } else {
                break;
            }
        }
        --j;
        ans += j + 1;
    }
    cout << ans;
    return 0;
}