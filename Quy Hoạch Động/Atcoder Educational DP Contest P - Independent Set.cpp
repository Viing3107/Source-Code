/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 23:28:22 - 14/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, dp[N][2];
vector<int> adj[N];

/*
    gọi dp[i][0] là số cách tô màu cây con gốc i sao cho i màu đen
    gọi dp[i][1] là số cách tô màu cây con gốc i sao cho i màu trắng

    dp[u][0] += dp[v][1] nếu tồn tại (u, v) và v là con u
    dp[u][1] += dp[v][0] + dp[v][1]

*/

void DFS(int u, int par = -1) {
    dp[u][0] = dp[u][1] = 1;
    for (auto &v : adj[u]) if (v != par) {
        DFS(v, u);
        (dp[u][0] *= dp[v][1]) %= MOD;
        (dp[u][1] *= dp[v][0] + dp[v][1]) %= MOD;
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

    cin >> n;
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    cout << (dp[1][0] + dp[1][1]) % MOD;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/atcoder_dp_p