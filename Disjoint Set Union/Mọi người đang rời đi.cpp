/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 21:17:24 - 11/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 1e6 + 5;

int n, m, x;
char type;

struct DisjointSetUnion {
    int par[N];

    void build() {
        forUp (i, 1, n + 1, 1) par[i] = i;
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

    cin >> n >> m;
    dsu.build();
    while (m--) {
        cin >> type >> x;
        if (type == '-') {
            dsu.joint(x, x + 1);
        }
        else {
            if (dsu.find(x) == n + 1) cout << -1 << endl;
            else cout << dsu.find(x) << endl;
        }
    }
    
    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/dsu_f