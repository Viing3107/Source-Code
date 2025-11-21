/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 17:52:19 - 21/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-6;
const int       N           = 3e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, q;
vector<int> adj[N];
int depth[N], sz[N], par[N];

void DFS(int u) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != par[u]) {
        par[v] = u;
        depth[v] = depth[u] + 1;
        DFS(v);
        sz[u] += sz[v];
    }
}

int in[N], out[N], arr[N], chainHead[N], chainId[N], curChain = 1, curPos;

void HLD(int u) {
    if (!chainHead[curChain]) chainHead[curChain] = u;
    chainId[u] = curChain;
    arr[++curPos] = u;
    in[u] = curPos;

    int bigChild = 0;
    for (auto &v : adj[u]) if (v != par[u] && sz[v] > sz[bigChild]) bigChild = v;
    if (bigChild) HLD(bigChild);

    for (auto &v : adj[u]) if (v != par[u] && v != bigChild) {
        curChain++;
        HLD(v);
    }

    out[u] = curPos;
}

int LCA(int u, int v) {
    if (chainId[u] > chainId[v]) swap(u, v);
    while (chainId[v] > chainId[u]) v = par[chainHead[chainId[v]]];
    return depth[u] < depth[v] ? u : v;
}

struct SegmentTree {
    int st[4 * N], lazy[4 * N];

    // SegmentTree() {
    //     memset(st, -0x3f, sizeof st);
    //     memset(lazy, 0, sizeof lazy);
    // }

    void push(int id, int l, int m, int r) {
        st[id * 2] += lazy[id];
        st[id * 2 + 1] += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        int m = l + r >> 1;
        push(id, l, m, r);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id, l, m, r);
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }

    void updatePath(int u, int v, int val) {
        int lca = LCA(u, v);
        for (; chainId[u] > chainId[lca]; u = par[chainHead[chainId[u]]]) update(1, 1, n, in[chainHead[chainId[u]]], in[u], val);
        for (; chainId[v] > chainId[lca]; v = par[chainHead[chainId[v]]]) update(1, 1, n, in[chainHead[chainId[v]]], in[v], val);
        (depth[u] < depth[v]) ? update(1, 1, n, in[u], in[v], val) : update(1, 1, n, in[v], in[u], val);
    }

    void updateSubTree(int u, int val) {
        update(1, 1, n, in[u], out[u], val);
    }

    int getPath(int u, int v) {
        int lca = LCA(u, v);
        int res = -INF;
        for (; chainId[u] > chainId[lca]; u = par[chainHead[chainId[u]]]) res = max(res, get(1, 1, n, in[chainHead[chainId[u]]], in[u]));
        for (; chainId[v] > chainId[lca]; v = par[chainHead[chainId[v]]]) res = max(res, get(1, 1, n, in[chainHead[chainId[v]]], in[v]));
        res = max(res, depth[u] < depth[v] ? get(1, 1, n, in[u], in[v]) : get(1, 1, n, in[v], in[u]));
        return res;
    }

    int getSubTree(int u) {
        return get(1, 1, n, in[u], out[u]);
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

    cin >> n >> q;
    forUp (i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    // forUp (i, 1, n, 1) cout << par[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << depth[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << sz[i] << " \n"[i == n];
    // forUp (i, 1, n, 1) cout << arr[i] << " \n"[i == n];
    while (q--) {
        int type, u, v, val;
        cin >> type;
        if (type == 1) {
            cin >> u >> v >> val;
            it.updatePath(u, v, val);
        }
        else if (type == 2) {
            cin >> u >> val;
            it.updateSubTree(u, val);
        }
        else if (type == 3) {
            cin >> u >> v;
            cout << it.getPath(u, v) << endl;
        }
        else {
            cin >> u;
            cout << it.getSubTree(u) << endl;
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

// https://oj.vnoi.info/problem/euler_j