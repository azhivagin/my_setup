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

const int inf = 1e8;

struct Point {
    int i, j;
    Point(int i_, int j_) {
        i = i_;
        j = j_;
    }
    Point() {}
    Point operator+(Point b) { return Point(i + b.i, j + b.j); }
};

vector<Point> moves(Point p) {
    return {Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)};
}

vector<vector<int>> bfs(Point s, const vector<vector<char>> &g, int n, int m) {
    queue<Point> q;
    q.push(s);
    vector<vector<int>> d(n, vector<int>(m, inf));
    d[s.i][s.j] = 0;
    while (!q.empty()) {
        Point v = q.front();
        q.pop();
        for (Point step : moves(v)) {
            Point p = v + step;
            if (p.i >= 0 && p.i < n && p.j >= 0 && p.j < m &&
                g[p.i][p.j] != '#') {
                int dist = d[v.i][v.j];
                if (step.j == 0) {
                    dist++;
                } else {
                    dist--;
                }
                if (abs(d[p.i][p.j]) > abs(dist)) {
                    q.push(p);
                    d[p.i][p.j] = dist;
                }
            }
        }
    }
    return d;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    Point start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 's') {
                start = {i, j};
            } else if (g[i][j] == 'f') {
                end = {i, j};
            }
        }
    }
    vector<vector<int>> res = bfs(start, g, n, m);
    cout << res[end.i][end.j];
    return 0;
}