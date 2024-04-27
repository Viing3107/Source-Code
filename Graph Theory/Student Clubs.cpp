# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, m, u, v, res, cnt;
vector<int> adj[N];
bool visited[N];

void DFS(int u){
	visited[u] = true;
	cnt++;
	for (vector<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++){
		if (!visited[*v]) DFS(*v);
	}
}

int factorial(int n){
	int res = 1;
	for (int i = 2; i <= n; i++){
		res *= i;
		res %= MOD;
	}
	return res;
}

signed main(){

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	memset(visited, false, sizeof visited);
	res = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			cnt = 0;
			DFS(i);
			if (cnt > 2) res += factorial(cnt);
			res %= MOD;
		}
	}
	cout << res % MOD;
	
	return 0;
}

// https://oj.vnoi.info/problem/icpc21_mt_m
