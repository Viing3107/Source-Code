/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:22:25 - 30/09/2025

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
const int       N           = 2e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

struct edge {
    int u, v, w;
};

int n, q, val[N], val2[N];
edge a[N];
vector<pair<int, int>> adj[N];
int chainHead[N], chainId[N], arr[N], pos[N], curPos, curChain = 1;
int par[N], depth[N], sz[N];

void DFS(int u) {
    sz[u] = 1;
    for (auto &x : adj[u]) {
        int v = x.first, w = x.second;
        if (v != par[u]) {
            val[v] = w;
            par[v] = u;
            depth[v] = depth[u] + 1;
            DFS(v);
            sz[u] += sz[v];
        }
    }
}

void HLD(int u) {
    if (!chainHead[curChain]) chainHead[curChain] = u;
    chainId[u] = curChain;
    arr[++curPos] = u;
    pos[u] = curPos;

    int bigChild = 0;
    for (auto &x : adj[u]) {
        int v = x.first;
        if (v != par[u] && sz[v] > sz[bigChild]) bigChild = v;
    }
    if (bigChild) HLD(bigChild);
    
    for (auto &x : adj[u]) {
        int v = x.first;
        if (v != bigChild && v != par[u]) {
            curChain++;
            HLD(v);
        }
    }
}

int LCA(int u, int v) {
    if (chainId[u] > chainId[v]) swap(u, v);
    while (chainId[v] > chainId[u]) v = par[chainHead[chainId[v]]];
    return depth[u] < depth[v] ? u : v;
}

struct SegmentTree {
    int st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) return void(st[id] = val2[l]);
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) return void (st[id] = val);
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }

    int query(int u, int v) {
        int lca = LCA(u, v), res = 0;
        for (; chainId[u] > chainId[lca]; u = par[chainHead[chainId[u]]]) res += get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]);
        for (; chainId[v] > chainId[lca]; v = par[chainHead[chainId[v]]]) res += get(1, 1, n, pos[chainHead[chainId[v]]], pos[v]);
        if (u != v) res += (depth[u] < depth[v]) ? get(1, 1, n, pos[u] + 1, pos[v]) : get(1, 1, n, pos[v] + 1, pos[u]);
        return res;
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp (i, 1, n - 1, 1) {
        cin >> a[i].u >> a[i].v >> a[i].w;
        adj[a[i].u].push_back({a[i].v, a[i].w});
        adj[a[i].v].push_back({a[i].u, a[i].w});
    }
    DFS(1);
    // cout << "par: "; forUp (i, 1, n, 1) cout << par[i] << " \n"[i == n];
    // cout << "sz: "; forUp (i, 1, n, 1) cout << sz[i] << " \n"[i == n];
    HLD(1);
    // cout << "arr: "; forUp (i, 1, n, 1) cout << arr[i] << " \n"[i == n];
    // cout << "pos: "; forUp (i, 1, n, 1) cout << pos[i] << " \n"[i == n];
    // cout << "val: "; forUp (i, 1, n, 1) cout << val[i] << " \n"[i == n];
    forUp (i, 1, n, 1) val2[i] = val[arr[i]];
    // cout << "val2: "; forUp (i, 1, n, 1) cout << val2[i] << " \n"[i == n];
    it.build(1, 1, n);
    cin >> q;
    while (q--) {
        int type, idx, val, u, v;
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            if (par[a[idx].v] == a[idx].u) it.update(1, 1, n, pos[a[idx].v], val);
            else it.update(1, 1, n, pos[a[idx].u], val);
        }
        else {
            cin >> u >> v;
            cout << it.query(u, v) << endl;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/euler_c