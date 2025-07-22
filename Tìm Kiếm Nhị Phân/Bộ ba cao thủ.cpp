/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:18:35 - 22/07/2025

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
const int       N           = 1e3 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N);
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, a[N][N];
bitset<N> par[N], child[N];
vector<int> adj[N];

void solve() {
    forUp(u, 1, n, 1) for (auto &v : adj[u]) {
        bitset<N> k = child[v] & par[u];
        int res = -1;
        if (k != 0) {
            int l = 0, r = 1000;
            while (r - l >= 0) {
                int m = l + r >> 1;
                if ((k >> m) != 0) {
                    l = m + 1;
                    res = m;
                }
                else r = m - 1;
            }
        }
        if (res != -1) return void(cout << u << " " << v << " " << res);
    }
    cout << -1 << " " << -1 << " " << -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
        cin >> a[i][j];
        if (a[i][j]) {
            adj[i].push_back(j);
            child[i].set(j);
            par[j].set(i);
        }
    }
    solve();
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/nktrio