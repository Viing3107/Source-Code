#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[N], topo;
bool visited[N];
int f[N];

void dfs(int u) {
    visited[u] = true;
    for (auto i : adj[u]) if (!visited[i]) dfs(i);
    topo.insert(topo.begin(), u);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    for (int i = 1; i <= n; ++i) if (!visited[i]) dfs(i);

    f[1] = 1;
    for (auto &u : topo) for (auto &v : adj[u]) (f[v] += f[u]) %= MOD;

    // for (int i = 1; i <= n; ++i) cout << f[i] << " ";
    cout << f[n];
}

// https://oj.vnoi.info/problem/fcb048_date