/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:32:09 - 18/06/2024

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

int n, m, cnt, result;
vector<int> adj[N], component;
bool visited[N];

void DFS(int u){
    cnt++;
    visited[u] = true;
    for (auto v : adj[u]) if (!visited[v]) DFS(v);
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
    forUp(i, 1, m, 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    result = cnt;
    forUp(u, 2, n, 1) if (!visited[u]){
        cnt = 0;
        DFS(u);
        component.push_back(cnt);
    }
    sort(component.begin(), component.end(), greater<int>());
    if (component.size() >= 1) cout << component[0] + result;
    else cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct018_nytravel