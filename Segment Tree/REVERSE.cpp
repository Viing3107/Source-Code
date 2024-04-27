# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 2e5 + 5;
int n, q, st[4 * N], lazy[4 * N], ind;
string s, res;

void update(int id, int l, int r, int u, int v){
	if (r < u || l > v) return;
	if (u <= l && r <= v){
		st[id]++;
		lazy[id]++;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v);
	update(id * 2 + 1, m + 1, r, u, v);
	st[id] = st[id * 2] + st[id * 2 + 1] + lazy[id];
}

int get(int id, int l, int r, int u, int v){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	int t1 = get(id * 2, l, m, u, v);
	int t2 = get(id * 2 + 1, m + 1, r, u, v);
	return t1 + t2 + lazy[id];
}

void input(){
	cin >> s;
	cin >> q;
}

void init(){
	n = s.size();
	s = "!" + s;
}

void solve(){
	while (q--){
		cin >> ind;
		update(1, 1, n, ind, n - ind + 1);
	}
	for (int i = 1; i * 2 <= n; i++){
		if (get(1, 1, n, i, i) % 2) swap(s[i], s[n - i + 1]);
	}
	res = "";
	for (int i = 1; i <= n; i++) res += s[i];
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

// https://oj.vnoi.info/problem/fcb003_reverse
