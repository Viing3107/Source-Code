/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 14:51:12 - 16/11/2025

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
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, m;

struct Edge {
    int u, v, w;

    friend bool operator < (const Edge &u, const Edge &v) {
        return u.w < v.w;
    }
};

vector<Edge> edges;

struct DisjointSetUnion {
    int par[N], sz[N];

    void build() {
        forUp (i, 1, n, 1) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u) {return u == par[u] ? u : par[u] = find(par[u]);}

    bool joint(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
} dsu;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp (i, 1, m, 1) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    sort(ALL(edges));
    dsu.build();
    int res = -INF;
    vector<Edge> MST;
    for (auto &e : edges) {
        if (dsu.joint(e.u, e.v)) {
            res = max(res, e.w);
            MST.push_back(e);
        }
    }
    if (SZ(MST) < n - 1) cout << "IMPOSSIBLE";
    else cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/fc075_range