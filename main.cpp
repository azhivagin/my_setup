#include <algorithm>
#include <cctype>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdio>
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

const int inf = 1e7;

// vector<int> f(string &s) {
//     vector<int> res;
//     int n = (int)s.size();
//     for (int i = 0; i < n; ++i) {
//         if (isupper(s[i])) {
//             res.push_back(i);
//         }
//     }
//     return res;
// }

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int n;
    // cin >> n;
    // map<string, vector<int>> mp;
    // for (int i = 0; i < n; ++i) {
    //     string s;
    //     cin >> s;
    //     vector<int> x = f(s);
    //     for (int i = 0; i < s.size(); ++i) {
    //         s[i] = tolower(s[i]);
    //     }
    //     mp[s].push_back(x[0]);
    // }
    // string t;
    // getline(cin, t);
    // getline(cin, t);
    // int ans = 0;
    // string p;
    // for (char c : t) {
    //     if (c == ' ') {
    //         vector<int> i = f(p);
    //         for (int i = 0; i < p.size(); ++i) {
    //             p[i] = tolower(p[i]);
    //         }
    //         if (mp.find(p) == mp.end() && i.size() > 0) {
    //             ++ans;
    //         } else if (find(mp[p].begin(), mp[p].end(), i[0]) == mp[p].end())
    //         {
    //             ++ans;
    //         }
    //         p.clear();
    //     } else {
    //         p.push_back(c);
    //     }
    // }
    // cout << ans;
    
    return 0;
}