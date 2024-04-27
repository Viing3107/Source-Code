# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 888;
bool visited[N], mark[N];
vector<int> adj[N];
ll cnt = 0, n, m;

void dfs(int u){
	visited[u] = true;
	for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++)
		if (!visited[*v]) dfs(*v);
}

void ccc(){  // count connected component :))
	memset(mark, false, sizeof mark);
	for (int i = 1; i <= n; i++)
		if (!visited[i]){
			mark[i] = true;
			dfs(i);
		}
	memset(visited, false, sizeof visited);
	for (int i = n; i >= 1; i--)
		if (mark[i] && !visited[i]){
			cnt++;
			dfs(i);
		}
	cout << cnt << endl;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	ccc();
	
	return 0;
}

// https://oj.vnoi.info/problem/message
