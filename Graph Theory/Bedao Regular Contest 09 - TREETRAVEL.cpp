/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:31:55 - 26/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
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
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, par[N], answer[N];
vector<int> adj[N];
int tour[N], tourSize, tin[N], tout[N];

void DFS(int u) {
    tour[++tourSize] = u;
    tin[u] = tourSize;
    for (auto &v : adj[u]) if (v != par[u]) DFS(v);
    tout[u] = tourSize;
}

struct SegmentTree{
    int st[4 * N];

    SegmentTree() {memset(st, 0, sizeof st);}

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = (st[id * 2] + st[id * 2 + 1]) % MOD;
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v)) % MOD;
    }

    void query(int u) {
        int x = (get(1, 1, n, tin[u], tout[u]) + 1) % MOD;
        answer[u] = x;
        update(1, 1, n, tin[u], x);
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
    int root;
    forUp(i, 1, n, 1) {
        cin >> par[i];
        if (!par[i]) root = i;
        adj[par[i]].push_back(i);
        adj[i].push_back(par[i]);
    }
    DFS(root);
    forUp(i, 1, n, 1) {
        int u;
        cin >> u;
        it.query(u);
    }
    forUp(i, 1, n, 1) cout << answer[i] << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_r09_treetravel