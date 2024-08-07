/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 18:01:43 - 07/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "TAITRONG"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e3 + 3;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, m, s, t, dp[N];
vector<pair<int, int>> adj[N];
bool visited[N];

void dijkstra(int s, int t) {
    vector<int> dp(N, 0);
    dp[s] = INF;
    priority_queue<pair<int, int>> Q;
    Q.push({INF, s});
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second, weight = top.first;
        for (auto &it : adj[u]) {
            int v = it.first, w = it.second;
            if (dp[v] < min(dp[u], w)) {
                dp[v] = min(dp[u], w);
                Q.push({dp[v], v});
            }
        }
    }
    cout << dp[t];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> s >> t;
    forUp(i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s, t);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/olp304_16_taitrong