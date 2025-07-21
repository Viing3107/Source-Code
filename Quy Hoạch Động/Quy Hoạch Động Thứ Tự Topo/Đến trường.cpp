#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e3 + 3;

struct edge {
    int u, v, w;
};

int n, m, d[N], visited[N], dp[N];
vector<pair<int, int>> adj[N];
vector<int> g[N], topo;
vector<edge> edges;

void dijkstra() {
    for (int i = 2; i <= n; i++) d[i] = LLONG_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, 1});
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second, weight = top.first;
        if (weight > d[u]) continue;
        for (auto &it : adj[u]) {
            int v = it.first, w = it.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
}

void DFS(int u) {
    visited[u] = true;
    for (auto &v : g[u]) if (!visited[v]) DFS(v);
    topo.insert(topo.begin(), u);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int type, u, v, w;
        cin >> type >> u >> v >> w;
        adj[u].push_back({v, w});
        edges.push_back({u, v, w});
        if (type == 2) {
            adj[v].push_back({u, w});
            edges.push_back({v, u, w});
        }
    }
    dijkstra();
    // for (int i = 1; i <= n; i++) cout << d[i] << " \n"[i == n];
    for (auto &e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (d[v] == d[u] + w) g[u].push_back(v);
    }
    DFS(1);
    dp[1] = 1;
    for (auto &u : topo) for (auto &v : g[u]) dp[v] += dp[u];
    cout << d[n] << " " << dp[n];
}

// https://oj.vnoi.info/problem/qbschool