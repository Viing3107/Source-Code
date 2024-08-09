/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:42:42 - 09/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N];

struct DisjointSetUnion {
    map<int, int> cnt[N];
    int par[N], sz[N];

    void build() {
        forUp(i, 1, n, 1) {
            par[i] = i;
            sz[i] = 1;
            cnt[i][a[i]]++;
        }
    }

    int find(int u) {return u == par[u] ? u : par[u] = find(par[u]);}

    void joint(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        for (auto &it : cnt[v]) cnt[u][it.first] += it.second;
        cnt[v].clear();
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
    forUp(i, 1, n, 1) cin >> a[i];
    dsu.build();
    while (q--) {
        int type, c, u, v;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            dsu.joint(u, v);
        }
        else {
            cin >> u >> c;
            u = dsu.find(u);
            cout << dsu.cnt[u][c] << endl;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/colquery