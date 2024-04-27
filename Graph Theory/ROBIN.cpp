# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma") 

using namespace std;
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l + (rng() * rng() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

const int N = 1e4 + 4;
int n, q, u, v, k, cnt, mark[N];
vector<int> adj[N];
bool visited[N];

void DFS(int u){
	visited[u] = true;
	mark[u] = cnt;
	for (auto v : adj[u]){
		if (!visited[v]) DFS(v);
	}
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> q;
	for (int u = 2; u <= n; u++){
		cin >> v >> k;
		if (k == 1){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
}

void init(){
	cnt = 1;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			DFS(i);
			cnt++;
		}
	}
}

void solve(){
	while (q--){
		cin >> u >> v;
		cout << (mark[u] != mark[v] ? "YES\n" : "NO\n");
	}
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/c11bc2