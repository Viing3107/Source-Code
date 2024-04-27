# include <bits/stdc++.h>
# define endl "\n"
# define ll long long

using namespace std;

const ll N = 1e4 + 4;
ll p, x, y, type, parent[N]; // parent[i] : node dai dien cho binh i

int get(int u){
	return (u == parent[u] ? u : parent[u] = get(parent[u]));
} 

void Check(int u, int v){
	u = get(u);
	v = get(v);
	cout << (u == v) ? "YES" : "NO";
	cout << endl;
}

void Union(int u, int v){
	u = get(u);
	v = get(v);
	parent[u] = v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 1; i < N; i++) parent[i] = i;
	cin >> p;
	while (p--){
		cin >> x >> y >> type;
		if (type % 2) Union(x, y);
		else Check(x, y);
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/ioibin
