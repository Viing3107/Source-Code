/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 00:57:59 02/09/2026

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
const int       N           = 5e3 + 5;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, dp[N], res = INF;
vector<int> adj[N];

void BFS(int u) {
    queue<int> Q;
    Q.push(u);
    dp[u] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : adj[u]) if (!dp[v]) {
            dp[v] = dp[u] + 1;
            Q.push(v);
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
    
    cin >> n;
    forUp (v, 1, n, 1) {
        int m;
        cin >> m;
        forUp (j, 1, m, 1) {
            int u;
            cin >> u;
            adj[u].push_back(v);
        }
    }
    forUp (u, 1, n, 1) {
        memset(dp, 0, sizeof dp);
        int sum = 0;
        BFS(u);
        forUp (u, 1, n, 1) {
            if (!dp[u]) {
                sum = INF;
                break;
            }
            sum += dp[u];
        }
        res = min(res, sum);
    }
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/fcc2022q4_salary