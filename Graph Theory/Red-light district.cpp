/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 18:03:22 - 25/10/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 2e5 + 5;
const int       INF         = 0x3f3f3f3f;

struct edge {
    int u, v;
    double dist;
} e;

int n, m, deg[N], s, t;
vector<pair<int, double>> adj[N];
double velocity;
vector<edge> E;

void dijkstra() {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
    Q.push({0, s});
    vector<double> T(N, INF);
    T[s] = 0;
    while (!Q.empty()) {
        pair<double, int> top = Q.top();
        Q.pop();
        int u = top.second;
        double Time = top.first;
        if (Time > T[u]) continue;
        for (auto &x : adj[u]) {
            int v = x.first;
            double Time = x.second;
            if (T[u] + Time < T[v]) {
                T[v] = T[u] + Time;
                Q.push({T[v], v});
            }
        }
    }
    // forUp (i, 1, n, 1) cout << T[i] << " \n"[i == n];
    cout << fixed << setprecision(6) << T[t];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> velocity;
    forUp (i, 1, m, 1) {
        cin >> e.u >> e.v >> e.dist;
        E.push_back(e);
        deg[e.u]++;
        deg[e.v]++;
    }
    cin >> s >> t;
    forUp (i, 0, m - 1, 1) {
        double time;
        time = E[i].dist / velocity;
        if (E[i].u != s && E[i].u != t && deg[E[i].u] > 2) time += deg[E[i].u] - 2;
        adj[E[i].u].push_back({E[i].v, time});
        time = E[i].dist / velocity;
        if (E[i].v != s && E[i].v != t && deg[E[i].v] > 2) time += deg[E[i].v] - 2;
        adj[E[i].v].push_back({E[i].u, time});
    }
    // forUp (u, 1, n, 1) {
    //     for (auto &x : adj[u]) {
    //         int v = x.first;
    //         double t = x.second;
    //         cout << "(" << v << " " << t << ")";
    //     }
    //     cout << endl;
    // }
    dijkstra();
}

//https://oj.vnoi.info/problem/icpc25_mt_l