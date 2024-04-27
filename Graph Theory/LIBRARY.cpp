# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e5 + 5;
ll n, m, a[N], cp, res;
vector<int> adj[N];
bool visited[N];


void dfs(int u){
	visited[u] = true;
	cp = min(cp, a[u]);
	for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if (!visited[*v]) dfs(*v);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	res = 0;
	memset(visited, false, sizeof visited);
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			cp = 1e9 + 7;
			dfs(i);
			res += cp;
		}
	}
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fct025_library
