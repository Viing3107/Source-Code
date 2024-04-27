# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 5e5 + 5;
int n, k, st[4 * N], lazy[4 * N], m, l, r;
string s, res;

void update(int id, int l, int r, int u, int v, int value){
	if (r < u || l > v) return;
	if (u <= l && r <= v){
		st[id] += value;
		lazy[id] += value;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, u, v, value);
	update(id * 2 + 1, m + 1, r, u, v, value);
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
	cin >> k;
}

void init(){
	n = s.size();
	s = "!" + s;
	res = "";
}

void calc(){
	while (k--){
		cin >> m >> l >> r;
		update(1, 1, n, l, r, m);
	}
	for (int i = 1; i <= n; i++){
		int tmp = get(1, 1, n, i, i) % 26;
		tmp = (s[i] - 97 + tmp) % 26 + 97;
		if (tmp > 90) tmp -= 26;
		res += tmp;
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
	calc();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/icpc21_mt_g
