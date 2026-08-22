/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 23:41:53 21/08/2026

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
const int    N          = 2e5 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, m, q, res, par[N][LOG(N) + 5], maxW[N][LOG(N) + 5], depth[N];

struct DisjointSetUnion {
    int par[N], sz[N];

    void build() {
        forUp (i, 1, n, 1) {
            par[i] = i;
            sz[i] = 1;
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

struct Edge {
    int u, v, w, id;
};

vector<Edge> edges, MST;
vector<pair<int, int>> adj[N];

void DFS(int u) {
    for (auto &[v, w] : adj[u]) {
        if (v == par[u][0]) continue;
        par[v][0] = u;
        maxW[v][0] = w;
        depth[v] = depth[u] + 1;
        for (int j = 1; MASK(j) <= n; j++) {
            par[v][j] = par[par[v][j - 1]][j - 1];
            maxW[v][j] = max(maxW[v][j - 1], maxW[par[v][j - 1]][j - 1]);
        }
        DFS(v);
    }
}

int solve(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u], res = -INF;
    for (int i = 0; MASK(i) <= d; i++) {
        if (BIT(i, d)) {
            res = max(res, maxW[v][i]);
            v = par[v][i];
        } 
    }
    if (u == v) return res;
    forDown (i, LOG(N), 0, -1) {
        if (par[u][i] != par[v][i]) {
            res = max({res, maxW[u][i], maxW[v][i]});
            u = par[u][i];
            v = par[v][i];
        }
    }
    res = max({res, maxW[u][0], maxW[v][0]});
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> m;
    forUp (i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }
    
    sort(ALL(edges), [&] (const Edge &u, const Edge &v) {
        return u.w < v.w;
    });
    dsu.build();
    for (int i = 0; i < SZ(edges) && SZ(MST) < n - 1; i++) {
        auto [u, v, w, id] = edges[i];
        if (dsu.join(u, v)) {
            res += w;
            MST.push_back({u, v, w});
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    DFS(1);
    // forUp (i, 1, n, 1) forUp (j, i + 1, n, 1) cout << i << " " << j << " " << maxW[i][j] << endl;
    sort(ALL(edges), [&] (const Edge &u, const Edge &v) {
        return u.id < v.id;
    });
    for (auto &[u, v, w, id] : edges) {
        cout << res - solve(u, v) + w << endl;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/tht21_tphcm_ckc_paths