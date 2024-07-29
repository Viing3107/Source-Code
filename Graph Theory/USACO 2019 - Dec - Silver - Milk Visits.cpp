/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:13:05 - 28/07/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;

int n, q, a[N];
string s;
vector<int> adj[N];
int par[N][LOG], depth[N];
int tour[2 * N], tourSize, in[N], out[N], f[2 * N], preSum[2 * N];

void DFS(int u) {
    tour[++tourSize] = u;
    in[u] = tourSize;
    for (auto &v : adj[u]) if (v != par[u][0]) {
        depth[v] = depth[u] + 1;
        par[v][0] = u;
        for (int i = 1; MASK(i) <= n; i++) par[v][i] = par[par[v][i - 1]][i - 1];
        DFS(v);
    }
    tour[++tourSize] = u;
    out[u] = tourSize;
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    for (int i = 0; MASK(i) <= d; i++) if (d >> i & 1) v = par[v][i];
    if (u == v) return u;
    int k = __lg(depth[u]);
    for (int i = k; i >= 0; i--) if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int dist(int u, int v) {return depth[u] + depth[v] - 2 * depth[LCA(u, v)] + 1;}

int get(int l, int r) {
    if (l > r) swap(l, r);
    return preSum[r] - preSum[l - 1];
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
    cin >> s;
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    forUp(i, 0, n - 1, 1) a[i + 1] = (s[i] == 'G');
    forUp(i, 1, n, 1) {
        f[in[i]] = a[i];
        f[out[i]] = -a[i];
    }
    forUp(i, 1, tourSize, 1) preSum[i] = preSum[i - 1] + f[i];
    while (q--) {
        int l, r;
        char type;
        cin >> l >> r >> type;
        int lca = LCA(l, r);
        if (type == 'H') cout << (get(in[lca], in[l]) + get(in[lca], in[r]) - f[in[lca]] != dist(l, r)); 
        else cout << (get(in[lca], in[l]) + get(in[lca], in[r]) - f[in[lca]] != 0);    
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/usaco19ds_milkvisits