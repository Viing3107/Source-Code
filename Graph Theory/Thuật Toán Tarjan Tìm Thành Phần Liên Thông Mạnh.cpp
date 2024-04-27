# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e4 + 4;
int n, m, u, v, cnt, Low[N], Num[N], res, tmp;
vector<int> adj[N];
stack<int> st;

void Tarjan(int u){
	Low[u] = Num[u] = ++cnt;
	st.push(u);
	for (auto v : adj[u]){
		if (Num[v]) Low[u] = min(Low[u], Num[v]);
		else{
			Tarjan(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if (Num[u] == Low[u]){
		res++;
		do{
			v = st.top();
			st.pop();
			Low[v] = Num[v] = 1e9;
		}while(v != u);
	}
}

void input(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
}

void init(){
	res = 0;
} 

void solve(){
	for (int i = 1; i <= n; i++){
		if (!Num[i]) Tarjan(i);
	}
}

void output(){
	cout << res << endl;
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

// https://oj.vnoi.info/problem/tjalg
