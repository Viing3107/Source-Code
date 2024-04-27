# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e4 + 4;
int n, m, u, v, low[N], num[N], bridge, articulation_point, cnt;
vector<int> adj[N];

void DFS(int u, int par){
	num[u] = low[u] = ++cnt;
	int node = (par != 0);
	for (auto v : adj[u]){
		if (v == par) continue;
		if (num[v]) low[u] = min(low[u], num[v]);
		else{
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == num[v]) bridge++;
			if (low[v] >= num[u]) node++;
		}
	}
	if (node >= 2) articulation_point++;
}

void input(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve(){
	for (int i = 1; i <= n; i++){
		if (!num[i]) DFS(i, 0);
	}
}

void output(){
	cout << articulation_point << " " << bridge << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
	output();
    
    return 0;
}

// https://oj.vnoi.info/problem/graph_
