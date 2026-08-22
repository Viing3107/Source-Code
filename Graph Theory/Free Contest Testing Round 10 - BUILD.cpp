/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 23:52:05 22/08/2026

*/

#include <bits/stdc++.h>
#define endl                   "\n"
#define task                   "test"
#define int                    long long
#define double                 long double
#define gcd(x, y)              __gcd(x, y)
#define MASK(i)                (1ll << (i))
#define SZ(v)                  (int)(v).size()
#define BIT(i, n)              ((n) >> (i) & 1)
#define lcm(x, y)              x / gcd(x, y) * y
#define ALL(v)                 (v).begin(), (v).end()
#define LOG(x)                 (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)   for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int    LEVEL      = 20;
const int    BASE       = 311;
const int    BLOCK_SIZE = 320;
const double EPS        = 1e-6;
const int    N          = 1e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n;

struct Point {
    int x, y, id;
} a[N];

struct Edge {
    int u, v, w;

    friend bool operator < (const Edge &u, const Edge &v) {
        return u.w < v.w;
    }
};

struct DisjointSetUnion {
    int par[N], sz[N];

    void build() {
        forUp (u, 1, n, 1) {
            par[u] = u;
            sz[u] = 1;
        }
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
} dsu;

vector<Edge> edges, MST;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, n, 1) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, [&] (const Point &u, const Point &v) {
        return u.x < v.x;
    });
    forUp (i, 2, n, 1) edges.push_back({a[i - 1].id, a[i].id, a[i].x - a[i - 1].x});
    sort(a + 1, a + n + 1, [&] (const Point &u, const Point &v) {
        return u.y < v.y;
    });
    forUp (i, 2, n, 1) edges.push_back({a[i - 1].id, a[i].id, a[i].y - a[i - 1].y});
    sort(ALL(edges));
    dsu.build();
    int res = 0;
    for (int i = 0; i < SZ(edges) && SZ(MST) < n - 1; i++) {
        auto [u, v, w] = edges[i];
        if (dsu.join(u, v)) {
            res += w;
            MST.push_back({u, v, w});
        }
    }
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/fct010_build