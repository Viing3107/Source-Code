# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e5 + 5;
int n, a[N], maximum, res, l, r;

void input(){
	cin >> n;
	maximum = -1e9;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maximum = max(maximum, a[i]);
	}
}

void solve(){
	res = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] == maximum || a[i] == 0) continue;
		l = 1;
		r = n;
		while (l < i && a[l] < a[i]) l++;
		if (l < i && a[l] >= a[i]) res = max(res, a[i] * max(0ll, abs(i - l) - 1));
		while (r > i && a[r] < a[i]) r--;
		if (r > i && a[r] >= a[i]) res = max(res, a[i] * max(0ll, abs(r - i) - 1));
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
	solve();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/fcc2022q1_watertank
