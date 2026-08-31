/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 17:24:46 31/08/2026

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
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-6;
const int       N           = 3e5 + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

int n, MOD, bestChild[N], res = 1;
double a[N], logA[N], dp[N];
vector<int> adj[N];

int binmul(int a, int n) {
    int res = 0;
    for (; n; n >>= 1, (a += a) %= MOD) if (n & 1) (res += a) %= MOD;
    return res;
}

void DFS(int u, int p = 0) {
    double maxChild = -INF;
    bestChild[u] = 0;
    for (auto v : adj[u]) if (v != p) {
        DFS(v, u);
        if (maxChild < dp[v]) {
            maxChild = dp[v];
            bestChild[u] = v;
        }
    }
    if (bestChild[u] == 0) dp[u] = logA[u];
    else dp[u] = logA[u] + maxChild;
}

void trace() {
    int cur = 1;
    while (cur) {
        res = binmul(res, a[cur]);
        cur = bestChild[cur];
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

    cin >> n >> MOD;
    forUp (i, 1, n, 1) {
        cin >> a[i];
        logA[i] = log10(a[i]);
    }
    // forUp (i, 1, n, 1) cout << a[i] << " \n"[i == n];
    forUp (i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    // forUp (i, 1, n, 1) cout << bestChild[i] << " \n"[i == n];
    trace();
    cout << res;

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/qtreev