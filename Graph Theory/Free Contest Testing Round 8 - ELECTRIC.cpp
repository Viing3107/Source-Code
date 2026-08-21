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
const int    N          = 4e3 + 5;
const int    VAL        = 1e6 + 6;
const int    MOD        = 1e9 + 7;
const int    INF        = 0x3f3f3f3f3f3f3f3f;

int n, m, q, res, maxW[N][N], trace[N];
bool visited[N];

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
    int u, v, w;

    friend bool operator < (const Edge &u, const Edge &v) {
        return u.w < v.w;
    }
};

vector<Edge> edges, MST;
vector<pair<int, int>> adj[N];

void DFS(int s, int u, int curMaxW) {
    visited[u] = true;
    maxW[s][u] = curMaxW;
    for (auto &[v, w] : adj[u]) if (!visited[v]) DFS(s, v, max(curMaxW, w));
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
        edges.push_back({u, v, w});
    }
    
    sort(ALL(edges));
    dsu.build();
    for (int i = 0; i < SZ(edges) && SZ(MST) < n - 1; i++) {
        auto [u, v, w] = edges[i];
        if (dsu.join(u, v)) {
            res += w;
            MST.push_back({u, v, w});
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    forUp (i, 1, n, 1) {
        memset(visited, false, sizeof visited);
        memset(trace, 0, sizeof trace);
        DFS(i, i, 0);
    }
    // forUp (i, 1, n, 1) forUp (j, i + 1, n, 1) cout << i << " " << j << " " << maxW[i][j] << endl;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << res - maxW[a][b] << endl;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/fct008_electric