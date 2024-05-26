# include <bits/stdc++.h>
# define int long long
# define name "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 3;
int n, m, u, v, a, b, w, weight, s, t, par[N];
vector<pair<int, int>> adj[N];
vector<int> path, d(N + 1, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

void input(){
	if (fopen(name".inp", "r")){
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> m >> s >> t;
	forUp(i, 1, m, 1){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
}

void dijkstra(int s, int t){
	d[s] = 0;
	Q.push({0, s});
	par[s] = s;
	while (!Q.empty()){
		pair<int, int> top = Q.top();
		Q.pop();
		u = top.second;
		weight = top.first;
		if(weight > d[u]) continue;
		for (auto it : adj[u]){
			v = it.first;
			w = it.second;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				par[v] = u;
			}
		}
	}
	cout << d[t] << endl;
	// Trace
	while (true){
        path.push_back(t);
        if (t == s) break;
        t = par[t];
	}
	reverse(path.begin(), path.end());
	forEach(it, path) cout << *it << " ";
}

void init(){
}

void solve(){
	dijkstra(s, t);
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

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/
