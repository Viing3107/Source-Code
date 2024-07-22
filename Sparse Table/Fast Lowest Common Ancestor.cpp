/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 12:58:21 - 22/07/2024

*/

#include                        <bits/stdc++.h>
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define minHigh(x, y)           (depth[x] < depth[y] ? x : y)
#define mask(i)                 (1ll << i)
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 2e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N);

int n, q, depth[N], tour[N], tourSize, pos[N], result;
vector<int> adj[N];

struct query{
    int start, jump, add;
} a, b;

struct SparseTable{
    int LCA[N * 2][LOG + 5];

    SparseTable() {memset(LCA, 0, sizeof LCA);}

    void build() {
        forUp(i, 1, tourSize, 1) LCA[i][0] = tour[i];
        forUp(j, 1, LOG, 1) forUp(i, 1, tourSize - mask(j) + 1, 1) LCA[i][j] = minHigh(LCA[i][j - 1], LCA[i + mask(j - 1)][j - 1]);
    }
    
    int get(int u, int v) {
        int pu = pos[u], pv = pos[v];
        if (pu > pv) swap(pu, pv);
        int k = 31 - __builtin_clz(pv - pu + 1);
        return minHigh(LCA[pu][k], LCA[pv - mask(k) + 1][k]);
    }
} st;

void DFS(int u, int p = 0) {
    tour[++tourSize] = u;
    pos[u] = tourSize;
    for (auto &v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        DFS(v, u);
        tour[++tourSize] = u;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    st.build();
    cin >> a.start >> b.start >> a.jump >> b.jump >> a.add >> b.add;
    forUp(i, 1, q, 1) {
        result ^= st.get(a.start, b.start);
        a.start = (1ll * a.start * a.jump + a.add) % n + 1;
        b.start = (1ll * b.start * b.jump + b.add) % n + 1;
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/euler_g