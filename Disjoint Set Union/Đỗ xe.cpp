/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 21:42:33 - 11/11/2025

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
const int       N           = 6e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, p[N];

struct DisjointSetUnion {
    int par[N];

    void build() {
        forUp (i, 1, 2 * n, 1) par[i] = i;
    }

    int find(int u) {return u == par[u] ? u : par[u] = find(par[u]);}

    void joint(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (u < v) swap(u, v);
        par[v] = u;
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

    cin >> n;
    forUp (i, 1, n, 1) cin >> p[i];
    dsu.build();
    forUp (i, 1, n, 1) {
        int pos = dsu.find(p[i]);
        if (pos > n) pos -= n;
        cout << pos << " ";
        dsu.joint(pos, pos + 1);
        dsu.joint(pos + n, pos + 1 + n);
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/dsu_g