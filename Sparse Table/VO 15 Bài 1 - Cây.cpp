/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:22:10 - 07/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define MIN_HIGH(u, v)          depth[u] < depth[v] ? (u) : (v)
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 7e4 + 4;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(2 * N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, q;
vector<int> adj[N];
int depth[N], tour[2 * N], tourSize, in[N];

void DFS(int u, int p = 0) {
    tour[++tourSize] = u;
    in[u] = tourSize;
    for (auto &v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        DFS(v, u);
        tour[++tourSize] = u;
    }
}

struct SparseTable {
    int minHigh[2 * N][LOG];

    void build() {
        forUp(i, 1, tourSize, 1) minHigh[i][0] = tour[i];
        for (int j = 1; MASK(j) <= tourSize; j++) for (int i = 1; i + MASK(j) - 1 <= tourSize; i++)
            minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }

    int LCA(int u, int v) {
        if (u == -1) {
            if (v == -1) return -1;
            return v;
        }
        if (v == -1) return u;
        int pu = in[u], pv = in[v];
        if (pu > pv) swap(pu, pv);
        int k = __lg(pv - pu + 1);
        return MIN_HIGH(minHigh[pu][k], minHigh[pv - MASK(k) + 1][k]);
    }
} st;

struct SegmentTree {
    int IT[4 * N];

    void build(int id, int l, int r) {
        if (l == r) {
            IT[id] = l;
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        IT[id] = st.LCA(IT[id * 2], IT[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return -1;
        if (u <= l && r <= v) return IT[id];
        int m = l + r >> 1;
        return st.LCA(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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
    st.build();
    it.build(1, 1, n);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << it.get(1, 1, n, u, v) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/votree