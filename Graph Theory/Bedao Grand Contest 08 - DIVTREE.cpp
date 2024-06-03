/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 08:20:27 - 03/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;
const int LOG   = __lg(N) + 1;

int n, q, res[N], a[N], u, v, par[N][LOG];
vector<int> adj[N], prime, lpf;
map<int, int> mark[N];

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    forUp(x, 3, n, 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++)
            lpf[prime[i] * x] = prime[i];
    }
}

void DFS(int u){
    for (auto v : adj[u]){
        if (v == par[u][0]) continue;
        par[v][0] = u;
        DFS(v);
        for (auto it : mark[v]) mark[u][it.first] += it.second;
    }
    for (; a[u] != 1; ){
        int y = lpf[a[u]];
        int cnt = 0;
        for (; a[u] % y == 0; a[u] /= y) cnt++;
        mark[u][y] += cnt;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    forUp(i, 1, n, 1) sort(adj[i].begin(), adj[i].end());
    sieve(N);
    
    DFS(1);
    forUp(i, 1, n, 1) res[i] = 1;
    forUp(i, 1, n, 1){
        for (auto it : mark[i]) (res[i] *= it.second + 1) %= MOD;
    }
    while (q--){
        int x;
        cin >> x;
        cout << res[x] << " ";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g08_divtree