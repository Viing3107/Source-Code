/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:51:42 - 21/07/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       N           = 1e3 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N);
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int n, in[N], dp[N];
pair<int, int> a[N];
set<int> adj[N];
vector<int> topo;

void kahn() {
    queue<int> q;
    forUp(u, 1, n, 1) if (!in[u]) q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto &v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".ans", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    forUp(i, 1, n - 2, 1) forUp(j, i + 1, n - 1, 1) forUp(k, j + 1, n, 1) if (a[i].first + a[j].first == a[k].first && adj[a[i].second].find(a[k].second) == adj[a[i].second].end() && adj[a[j].second].find(a[k].second) == adj[a[j].second].end()) {
        adj[a[i].second].insert(a[k].second);
        adj[a[j].second].insert(a[k].second);
        in[a[k].second]++;
        in[a[k].second]++;
    }
    // forUp(i, 1, n, 1) {
    //     cout << i << "     ";
    //     for (auto &x : adj[i]) cout << x << " ";
    //     cout << endl;
    // }
    // forUp(u, 1, n, 1) cout << in[u] << " \n"[u == n];
    kahn();
    // forUp(u, 1, n, 1) cout << topo[u] << " \n"[u == n];
    forUp(u, 1, n, 1) dp[u] = 1;
    for (auto &u : topo) for (auto &v : adj[u]) dp[v] = max(dp[v], dp[u] + 1);
    // forUp(u, 1, n, 1) cout << dp[u] << " \n"[u == n];
    cout << *max_element(dp + 1, dp + n + 1);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/nkjump