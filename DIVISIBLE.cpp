# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b
# define name "test"

using namespace std;

int q, l, r, res, tmp, u, v;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
}

void init(){
}

void solve(){
	cin >> q;
	while (q--){
		res = 0;
		cin >> l >> r;
		u = l;
		v = r;
		while (u < v && u % 4) u++;
		while (u < v && v % 4) v--;
		if (u % 4 == 0) res += ((v - u) / 4 + 1);
		u = l;
		v = r;
		while (u < v && u % 7) u++;
		while (u < v && v % 7) v--;
		if (u % 7 == 0) res += ((v - u) / 7 + 1);
		u = l;
		v = r;
		while (u < v && u % 11) u++;
		while (u < v && v % 11) v--;
		if (u % 11 == 0) res += ((v - u) / 11 + 1);
		u = l;
		v = r;
		tmp = lcm(4, 7);
		while (u < v && u % tmp) u++;
		while (u < v && v % tmp) v--;
		if (u % tmp == 0) res -= ((v - u) / tmp + 1);
		u = l;
		v = r;
		tmp = lcm(4, 11);
		while (u < v && u % tmp) u++;
		while (u < v && v % tmp) v--;
		if (u % tmp == 0) res -= ((v - u) / tmp + 1);
		u = l;
		v = r;
		tmp = lcm(7, 11);
		while (u < v && u % tmp) u++;
		while (u < v && v % tmp) v--;
		if (u % tmp == 0) res -= ((v - u) / tmp + 1);
		u = l;
		v = r;
		tmp = lcm(4, lcm(7, 11));
		while (u < v && u % tmp) u++;
		while (u < v && v % tmp) v--;
		if (u % tmp == 0) res += ((v - u) / tmp + 1);
		cout << res << endl;
	}
}

void output(){
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

// https://oj.vnoi.info/problem/fcb006_divisible