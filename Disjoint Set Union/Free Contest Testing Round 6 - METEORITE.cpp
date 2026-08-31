/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 01:20:29 01/09/2026

*/

#include <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int)(v).size()
#define BIT(i, n)               ((n) >> (i) & 1)
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i -= step)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-6;
const int       N           = 3e5 + 5;
const int       M           = 2e5 + 5;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int u, v;
};

struct Query {
    int id, c;
};

int n, m, q, ans[M];
Edge edges[M];
Query queries[M];
int cntQuery[M];

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

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
} dsu;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> m >> q;
    forUp (i, 1, m, 1) cin >> edges[i].u >> edges[i].v;
    forUp (i, 1, q, 1) {
        cin >> queries[i].id >> queries[i].c;
        cntQuery[queries[i].id]++;
    }
    // forUp (i, 0, q - 1, 1) cout << queries[i].id << " " << queries[i].c << endl;
    dsu.build();
    forUp (i, 1, m, 1) if (!cntQuery[i]) dsu.join(edges[i].u, edges[i].v);
    // forUp (i, 0, m - 1, 1) cout << hasQuery[i] << " \n"[i == m - 1];
    forDown (i, q, 1, 1) {
        auto [id, c] = queries[i];
        ans[i] = dsu.sz[dsu.find(c)];
        cntQuery[id]--;
        if (!cntQuery[id]) dsu.join(edges[id].u, edges[id].v);
    }
    forUp (i, 1, q, 1) cout << ans[i] << endl;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/fct006_meteorite