/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:59:40 - 07/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e6 + 6;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, m, k, a[N], result[N];
vector<int> adj[N];
queue<int> Q;

void BFS() {
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto &v : adj[u]) {
            if (result[v] == INF) Q.push(v);
            result[v] = min(result[v], result[u] + 1);
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

    cin >> n >> m >> k;
    memset(result, 0x3f, sizeof result);
    forUp(i, 1, k, 1) {
        int x;
        cin >> x;
        result[x] = 0;
        Q.push(x);
    }
    forUp(i, 1, m, 1) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    BFS();
    forUp(i, 1, n, 1) cout << (result[i] == INF ? -1 : result[i]) << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc091_nmarket