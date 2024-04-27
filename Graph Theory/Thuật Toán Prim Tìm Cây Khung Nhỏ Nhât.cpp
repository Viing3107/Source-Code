# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e4 + 4;
vector<pair<int, int> > adj[N];
bool visited[N];
int res, n, m;

void prim(int s){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, s});
	while (!q.empty()){
		pair<int, int> top = q.top();
		q.pop();
		int u = top.second;
		int t = top.first;
		if (visited[u]) continue;
		res = max(res, t);
		visited[u] = true;
		for (vector<pair<int, int> >::iterator v = adj[u].begin(); v != adj[u].end(); v++){
			int dinh = (*v).first;
			int time = (*v).second;
			if (!visited[dinh]) q.push({time, dinh});
		}
	}
	cout << res << endl;
}


int main(){

	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back(make_pair(v, t));
		adj[v].push_back(make_pair(u, t));
	}
	memset(visited, false, sizeof visited);
	res = 0;
	prim(1);

	return 0;
}

// https://oj.vnoi.info/problem/nkcity
