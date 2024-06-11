/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:35:08 - 11/06/2024

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

int result[N], n, m, a[N], u, v;
vector<int> adj[N];
set<int> cnt[N];

void DFS(int u, int par){
    cnt[u].insert(a[u]);
    for (auto v : adj[u]){
        if (v == par) continue;
        DFS(v, u);
        if (cnt[u].size() < cnt[v].size()) swap(cnt[u], cnt[v]);
        for (auto it : cnt[v]) cnt[u].insert(it);
    }
    result[u] = cnt[u].size() == m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    forUp(i, 1, n, 1) cout << result[i];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb028_agrtree