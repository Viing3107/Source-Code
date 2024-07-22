/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 19:29:25 - 22/07/2024

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

const int N             = 1e4 + 4;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, k, sz[N], result;
vector<int> adj[N];

void DFS(int u, int p = 0) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        DFS(v, u);
        sz[u] += sz[v];
    }
    if (sz[u] >= k) {
        result++;
        sz[u] = 0;
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

    cin >> k >> n;
    forUp(i, 2, n, 1) {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    DFS(1);
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/v8org