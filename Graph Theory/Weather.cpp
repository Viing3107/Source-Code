# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 3e5 + 5;
vector<int> adj[N];
int n, m, Time, low[N], num[N], ans, u, v, par[N], sz[N];

void dfs(int u){
    num[u] = ++Time; 
    low[u] = N;
    sz[u] = 1;
    for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++) if (*v != par[u]){
        if (num[*v] == 0){
            par[*v] = u;
            dfs(*v);
            low[u] = min(low[u], low[*v]);
            sz[u] += sz[*v];
        }
        else low[u] = min(low[u], num[*v]);
    }
}

void input(){
// 	freopen("ddk.inp", "r", stdin);
// 	freopen("ddk.out", "w", stdout);
	cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve(){
	dfs(1);
    ans = 0;
    for (int v = 2; v <= n; v++){
        if (low[v] >= num[v]) ans += sz[v] * (n - sz[v]);
    }
    cout << ans << endl;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    input();
    solve();

    return 0;
}
