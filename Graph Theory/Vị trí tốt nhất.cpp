/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 21:28:34 02/09/2026

*/

#include <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int)(v).size()
#define BIT(i, n)               ((n) >> (i) & 1)
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i -= step)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-6;
const int       N           = 5e2 + 5;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int p, n, m, f[N];
vector<pair<int, int>> adj[N];
vector<int> d, t;

void dijkstra(int s) {
    d.assign(p + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while (!Q.empty()) {
        auto [w, u] = Q.top();
        Q.pop();
        if (w > d[u]) continue;
        for (auto [v, weight] : adj[u]) if (d[v] > d[u] + weight) {
            d[v] = d[u] + weight;
            Q.push({d[v], v});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> p >> n >> m;
    forUp (i, 1, n, 1) cin >> f[i];
    forUp (i, 1, m, 1) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    t.assign(p + 1, 0);
    forUp (i, 1, n, 1) {
        dijkstra(f[i]);
        forUp (u, 1, p, 1) t[u] += d[u];
    }
    // forUp (u, 1, p, 1) cout << t[u] << " \n"[u == p];
    int bestTime = INF;
    forUp (i, 1, p, 1) bestTime = min(bestTime, t[i]);
    forUp (i, 1, p, 1) {
        if (t[i] == bestTime) {
            cout << i;
            return 0;
        }
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/bestspot