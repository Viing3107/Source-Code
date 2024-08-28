#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 3e5 + 5;

int n, q;
vector<int> adj[N];
int tour[N], tourSize, in[N], out[N];

void DFS(int u, int p = 0) {
    tour[++tourSize] = u;
    in[u] = tourSize;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    out[u] = tourSize;
}

struct SegmentTree {
    double st[4 * N];

    void update(int id, int l, int r, int idx, double val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    double get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    // for (int i = 1; i <= n; i++) cout << tour[i] << " \n"[i == n];
    cin >> q;
    while (q--) {
        int type, u, v, val;
        cin >> type;
        if (type == 1) {
            cin >> u >> val;
            it.update(1, 1, n, in[u], log10(val));
        }
        else {
            cin >> u >> v;
            double k = it.get(1, 1, n, in[u], out[u]) - it.get(1, 1, n, in[v], out[v]);
            if (k > 9) k = 9;
            cout << fixed << setprecision(10) << pow(10, k) << "\n";
        }
    }
}

// https://oj.vnoi.info/problem/secondthread_tree_richtree