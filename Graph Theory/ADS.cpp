# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 2e3 + 3;
vector<int> adj[N];
bool visited[N];
int n, m;

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++){
			if (!visited[*it]){
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(visited, false, sizeof visited);
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			res++;
			bfs(i);
		}
	}
	cout << m - n + res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/ads
