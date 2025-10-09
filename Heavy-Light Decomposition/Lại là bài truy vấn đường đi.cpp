/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:37:50 - 18/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N];
vector<int> adj[N];
int par[N];
int sz[N];
int depth[N];
int arr[N];
int pos[N];
int chainId[N];
int chainHead[N];
int curChain = 1, curPos;

void DFS(int u, int p = 0) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        par[v] = u;
        DFS(v, u);
        sz[u] += sz[v];
    }
}

void HLD(int u, int p = 0) {
    if (!chainHead[curChain]) chainHead[curChain] = u;
    chainId[u] = curChain;
    pos[u] = ++curPos;
    arr[curPos] = u;

    int bigChild = 0;
    for (auto &v : adj[u]) if (v != p) {
        if (sz[v] > sz[bigChild]) bigChild = v;
    }

    if (bigChild) HLD(bigChild, u);

    for (auto &v : adj[u]) if (v != p && v != bigChild) {
        curChain++;
        HLD(v, u);
    }
}

int LCA(int u, int v) {
    if (chainId[u] > chainId[v]) swap(u, v);
    while (chainId[u] < chainId[v]) v = par[chainHead[chainId[v]]];
    return ((depth[u] < depth[v]) ? u : v);
}

struct SegmentTree{
    int st[4 * N];

    SegmentTree() {memset(st, -0x3f, sizeof st);}

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[arr[l]];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return -INF;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }

    int query(int u, int v) {
        int lca = LCA(u, v), result = -INF;
        for (; chainId[u] > chainId[lca]; u = par[chainHead[chainId[u]]]) result = max(result, get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]));
        for (; chainId[v] > chainId[lca]; v = par[chainHead[chainId[v]]]) result = max(result, get(1, 1, n, pos[chainHead[chainId[v]]], pos[v]));
        if (depth[u] < depth[v]) result = max(result, get(1, 1, n, pos[u], pos[v]));
        else result = max(result, get(1, 1, n, pos[v], pos[u]));
        return result;
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
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    it.build(1, 1, n);
    while (q--) {
        int type, u, v, val;
        cin >> type;
        if (type == 1) {
            cin >> u >> val;
            it.update(1, 1, n, pos[u], val);
        }
        else {
            cin >> u >> v;
            cout << it.query(u, v) << " ";
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

// https://oj.vnoi.info/problem/euler_h