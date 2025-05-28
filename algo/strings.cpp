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

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (l <= i && i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> prefix_function(string &s) {
    int n = (int)s.size();
    vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int cur = p[i - 1];
        while (s[cur] != s[i] && cur > 0) {
            cur = p[cur - 1];
        }
        if (s[i] == s[cur]) {
            p[i] = cur + 1;
        }
    }
    return p;
}

// HASH
// const long long k = 31, mod = 1e9 + 7;

struct Hash {
    int n;
    long long k, mod;
    vector<long long> h, p;
    Hash(string &s, long long k_, long long mod_) {
        n = (int)s.size();
        k = k_;
        mod = mod_;
        h.resize(n + 1);
        p.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i] * k + s[i]) % mod;
            p[i + 1] = (p[i] * k) % mod;
        }
    }
    long long hash_substring(int l, int r) {  // 0-index
        if (l > r) {
            return 0;
        }
        return (h[r + 1] - h[l] * p[r - l + 1] % mod + mod) % mod;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}