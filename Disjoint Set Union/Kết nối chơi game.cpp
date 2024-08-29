#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, q, a[N], answer[N], cnt[N];
vector<int> adj[N];
unordered_map<int, int> mp[N];

struct DisjointSetUnion {
    int sz[N], par[N];

    void build() {
        for (int i = 1; i <= n; i++) {
            sz[i] = 1;
            par[i] = i;
            mp[i][a[i]]++;
        }
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
} dsu;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) answer[i] = cnt[i] == 1 ? 0 : -1;
    dsu.build();
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        u = dsu.find(u);
        v = dsu.find(v);
        if (u == v) continue;
        if (dsu.sz[u] < dsu.sz[v]) swap(u, v);
        dsu.par[v] = u;
        dsu.sz[u] += dsu.sz[v];
        for (auto &x : mp[v]) {
            mp[u][x.first] += x.second;
            if (mp[u][x.first] == cnt[x.first] && answer[x.first] == -1) answer[x.first] = i;
        }
    }
    for (int i = 1; i <= m; i++) cout << answer[i] << "\n";
}

// https://oj.vnoi.info/problem/vosplay