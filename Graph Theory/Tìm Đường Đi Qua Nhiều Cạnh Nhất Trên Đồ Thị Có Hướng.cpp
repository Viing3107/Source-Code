# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, res; 
vector<int> adj[N];
vector<int> dp(N);

int dfs(int u){
	if (dp[u]) return dp[u];
	for (auto v : adj[u]){
		dp[v] = dfs(v);
		dp[u] = max(dp[u], dp[v] + 1);
	}
	return dp[u];
}

int main(){
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) dfs(i);
	res = 0;
	for (int i = 1; i <= n; i++) res = max(res, dp[i]);
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/atcoder_dp_g

