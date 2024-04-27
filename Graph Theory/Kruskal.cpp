# include <bits/stdc++.h>
# define int long long

using namespace std;

struct edge{
	int u, v, w;

	friend bool operator < (edge a, edge b){
        return a.w < b.w;
	}
};

const int N = 1e4 + 4;
int n, m, par[N], sz[N], res;
vector<edge> adj, MST;
edge e;

void make_set(){
	for (int i = 1; i <= n; i++){
		par[i] = i;
		sz[i] = 1;
	}
}

int find (int v){
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool union_set(int u, int v){
	u = find(par[u]);
	v = find(par[v]);
	if (u == v) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u;
	sz[u] += sz[v];
	return true;
}

void input(){
	if (fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> e.u >> e.v >> e.w;
		adj.push_back(e);
	}
}

void init(){
	make_set();
}

void Kruskal(){
	int d = 0;
	sort(adj.begin(), adj.end());
	for (auto it : adj){
		if (MST.size() == n - 1) break;
		if (union_set(it.u, it.v)){
			MST.push_back(it);
			d += it.w;
		}
	}
	cout << d << endl;
	// Trace
	for (auto it : MST) cout << it.u << " " << it.v << " " << it.w << endl;
}

void output(){
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	Kruskal();
	output();

	return 0;
}

// https://oj.vnoi.info/problem/qbmst
