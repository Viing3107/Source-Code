/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 19:57:31 - 16/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const int       N           = 3e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, minDist;

struct Point {
    int x, y, z;

    Point() : x(0), y(0), z(0) {}
    Point(int x, int y, int z) : x(x), y(y), z(z) {}

    friend istream& operator >> (istream &stream, Point &u) {
        stream >> u.x >> u.y >> u.z;
        return stream;
    }

    friend ostream& operator << (ostream &stream, Point u) {
        stream << u.x << " " << u.y << " " << u.z;
        return stream;
    }

    friend int dist(const Point &u, const Point &v) {
        return abs(u.x - v.x) + abs(u.y - v.y) + abs(u.z - v.z);
    }
} p[N], home;

int f(int x, int type) {
    int res = 0;
    forUp (i, 1, n, 1) {
        if (type == 1) res += abs(x - p[i].x);
        else if (type == 2) res += abs(x - p[i].y);
        else res += abs(x - p[i].z);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> home;
    forUp (i, 1, n, 1) {
        cin >> p[i];
        minDist += dist(home, p[i]);
    }
    int l, r;
    Point res;
    l = 0, r = 1e9;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m, 1) <= f(m + 1, 1)) {
            res.x = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    l = 0, r = 1e9;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m, 2) <= f(m + 1, 2)) {
            res.y = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    l = 0, r = 1e9;
    while (r - l >= 0) {
        int m = l + r >> 1;
        if (f(m, 3) <= f(m + 1, 3)) {
            res.z = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    cout << minDist;

    // forUp (i, 1, n, 1) minDist += dist(res, p[i]);
    // cout << minDist << endl << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc099_endgame