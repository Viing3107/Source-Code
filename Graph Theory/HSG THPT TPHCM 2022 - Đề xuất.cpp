#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 4;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m, k, s, t, from[N], to[N];
vector<pair<int, int> > adj[N], r_adj[N];

void dijkstraStart() {
    vector<int> d(N, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(d[s], s));
    while (!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second, dist = top.first;
        if (dist > d[u]) continue;
        for (vector<pair<int, int> >::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = (*it).first, w = (*it).second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(make_pair(d[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) from[i] = d[i];
}

void dijkstraEnd() {
    vector<int> d(N, INF);
    d[t] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push(make_pair(d[t], t));
    while (!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();
        int u = top.second, dist = top.first;
        if (dist > d[u]) continue;
        for (vector<pair<int, int> >::iterator it = r_adj[u].begin(); it != r_adj[u].end(); it++) {
            int v = (*it).first, w = (*it).second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push(make_pair(d[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++) to[i] = d[i];
}

int choose(int u, int v, int w) {
    if (from[u] == INF || to[v] == INF) {
        if (from[v] == INF || to[u] == INF) return from[t];
        return min(from[t], from[v] + w + to[u]);
    }
    return min(from[t], min(from[v] + w + to[u], from[u] + w + to[v]));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        r_adj[v].push_back(make_pair(u, w));
    }
    dijkstraStart();
    dijkstraEnd();
    int res = INF;
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        res = min(res, choose(u, v, w));
    }
    if (res == INF) cout << -1;
    else cout << res;
}

// https://oj.vnoi.info/problem/hcm_thpt_22_c
