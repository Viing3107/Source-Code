# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optimize("O2")

using namespace std;

const int N = 1e5 + 5;
int n, m, p, u, v, cnt;
vector<int> adj[N];
bool visited[N], check, ok;

bool DFS(int u){
	visited[u] = true;
	cnt++;
	if (!adj[u].size()) return true;
	ok = false;
	for (auto v : adj[u]){
		if (!visited[v]){
			ok = true;
			DFS(v);
			break;
		}
	}
	return ok;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	cin >> m >> n >> p;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		adj[v].push_back(u);
	}
}

void init(){
	cnt = 0;
}

void solve(){
	if (DFS(p)){
		if (cnt != 1) cout << cnt - 1 << endl;
		else cout << -1 << endl;
	}
	else cout << -1 << endl;
}

void output(){
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	init();
	solve();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc097_tv