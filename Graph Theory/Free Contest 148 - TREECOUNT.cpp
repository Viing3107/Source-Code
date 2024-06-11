/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:51:58 - 11/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define all(v)                  v.begin(), v.end()

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], result[N];
vector<int> adj[N], cnt[N];

void DFS(int u, int par){
    cnt[u].push_back(a[u]);
    for (auto v : adj[u]){
        if (v == par) continue;
        DFS(v, u);
        if (cnt[u].size() < cnt[v].size()) swap(cnt[u], cnt[v]);
        for (auto it : cnt[v]){
            int idx = lower_bound(all(cnt[u]), it) - cnt[u].begin();
            cnt[u].insert(cnt[u].begin() + idx, it);    
        }
    }
    result[u] = cnt[u].size() - (lower_bound(all(cnt[u]), a[u] + 1) - cnt[u].begin());
}

void process(){
    vector<int> b;
    forUp(i, 1, n, 1) b.push_back(a[i]);
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    forUp(i, 1, n, 1) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    process();
    forUp(u, 2, n, 1){
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    forUp(i, 1, n, 1) cout << result[i] << endl;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc148_treecount