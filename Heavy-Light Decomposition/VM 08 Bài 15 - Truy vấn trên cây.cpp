/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:32:23 - 19/07/2024

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

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], sz[N], par[N], depth[N], chainHead[N], chainId[N], arr[N], pos[N], curChain = 1, curPos;
vector<int> adj[N];

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
    arr[++curPos] = u;
    pos[u] = curPos;

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

struct SegmentTree{
    int *st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = &a[arr[l]];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = (((*st[id * 2]) < (*st[id * 2 + 1])) ? st[id * 2 + 1] : st[id * 2]);
    }

    void update(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return;
        if (l == r) {
            (*st[id]) ^= 1;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx);
        update(id * 2 + 1, m + 1, r, idx);
        st[id] = (((*st[id * 2]) < (*st[id * 2 + 1])) ? st[id * 2 + 1] : st[id * 2]);
    }

    int *get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return &a[n + 1];
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        int *t1 = get(id * 2, l, m, u, v);
        int *t2 = get(id * 2 + 1, m + 1, r, u, v);
        return (((*t1) < (*t2)) ? t2 : t1);
    }

    int query(int u) {
        int result = -1;
        for (; chainId[u] > 1; u = par[chainHead[chainId[u]]]) {
            int *tmp = get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]);
            if (*tmp) result = tmp - a;
        }
        int *tmp = get(1, 1, n, 1, pos[u]);
        if (*tmp) result = tmp - a;
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
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    // forUp(i, 1, n, 1) cout << arr[i] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << pos[i] << " ";
    // cout << endl;
    it.build(1, 1, n);
    while (q--) {
        int type, u;
        cin >> type >> u;
        if (type) cout << it.query(u) << endl;
        else it.update(1, 1, n, pos[u]);
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/qtree3