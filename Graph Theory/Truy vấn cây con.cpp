#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
vector<int> adj[N];
int tour[N], tourSize, in[N], out[N];

void DFS(int u, int p = 0) {
    tour[++tourSize] = u;
    in[u] = tourSize;
    for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++) if (*v != p) DFS(*v, u);
    out[u] = tourSize;
}

struct SegmentTree {
    struct node {
        int val, lazy;
    } st[4 * N];

    void push(int id, int l, int r, int m) {
        st[id * 2].val += (m - l + 1) * st[id].lazy;
        st[id * 2 + 1].val += (r - m) * st[id].lazy;
        st[id * 2].lazy += st[id].lazy;
        st[id * 2 + 1].lazy += st[id].lazy;
        st[id].lazy = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (r < u || l > v) return;
        if (u <= l && r <= v) {
            st[id].val += (r - l + 1) * val;
            st[id].lazy += val;
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    }

    int get(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return 0;
        if (l == r) return st[id].val;
        int m = l + r >> 1;
        push(id, l, r, m);
        return get(id * 2, l, m, idx) + get(id * 2 + 1, m + 1, r, idx);
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
//    for (int i = 1; i <= n; i++) cout << tour[i] << " \n"[i == n];
//    for (int i = 1; i <= n; i++) cout << in[i] << " " << out[i] << endl;
    while (q--) {
        int u, val;
        cin >> u >> val;
        it.update(1, 1, n, in[u], out[u], val);
    }
    for (int i = 1; i <= n; i++) cout << it.get(1, 1, n, in[i]) << " ";
}

// https://marisaoj.com/problem/189
