/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

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
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 3e5 + 5;
const int       BASE        = 31;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, q;

struct DisjointSetUnion {
    int par[N], sz[N], minimum[N], maximum[N];

    void build() {
        forUp (i, 1, n, 1) {
            par[i] = i;
            sz[i] = 1;
            minimum[i] = i;
            maximum[i] = i;
        }
    }

    int find(int u) {return u == par[u] ? u : find(par[u]);}

    void joint(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        minimum[u] = min(minimum[u], minimum[v]);
        maximum[u] = max(maximum[u], maximum[v]);
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

    cin >> n >> q;
    dsu.build();
    while (q--) {
        string type;
        int u, v;
        cin >> type;
        if (type == "union") {
            cin >> u >> v;
            dsu.joint(u, v);
        }
        else {
            cin >> u;
            u = dsu.find(u);
            cout << dsu.minimum[u] << " " << dsu.maximum[u] << " " << dsu.sz[u] << endl;
        }
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/dsu_b
