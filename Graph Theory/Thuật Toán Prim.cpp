#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e4 + 4;
int n, m, x, y, w;
vector<pair<int, int>> adj[N];
bool visited[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void prim(){
	int res = 0;
	q.push({0, 1});
	while (!q.empty()){
		pair<int, int> top = q.top();
		q.pop();
		int u = top.second;
		int weight = top.first;
		if (visited[u]) continue;
		res += weight;
		visited[u] = true;
		for (auto it : adj[u]){
			y = it.first;
			w = it.second;
			if (!visited[y]) q.push({w, y});
		}
	}
	cout << res << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	prim();
	
	return 0;
}

// https://oj.vnoi.info/problem/qbmst
