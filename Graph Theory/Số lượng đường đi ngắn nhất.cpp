/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:33:47 - 10/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               (n >> i & 1)
#define all(v)                  (v).begin(), (v).end()
#define MIN_HIGH(x, y)          depth[x] < depth[y] ? (x) : (y)
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       N           = 2e5 + 5;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

struct edge {
    int u, v, w;
};

int n, m, dp[N], deg[N];
vector<pair<int, int>> adj[N];
vector<edge> edges;
vector<int> d(N, INF), g[N], topo;

void dijkstra(int s, int t) {
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({d[s], s});
    while (!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second, dist = top.first;
        if (dist > d[u]) continue;
        for (auto &it : adj[u]) {
            int v = it.first, w = it.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

void kahn() {
    queue<int> q;
    forUp(u, 1, n, 1) if (!deg[u]) q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto &v : g[u]) {
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    dijkstra(1, n);
    for (auto &e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (d[v] == d[u] + w) {
            g[u].push_back(v);
            deg[v]++;
        }
        else if (d[u] == d[v] + w) {
            g[v].push_back(u);
            deg[u]++;
        }
    }
    kahn();
    // for (auto &u : topo) cout << u << " ";
    dp[1] = 1;
    for (auto &u : topo) for (auto &v : g[u]) (dp[v] += dp[u]) %= MOD;
    cout << dp[n];

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://marisaoj.com/problem/175