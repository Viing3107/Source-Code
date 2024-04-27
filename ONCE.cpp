# include <bits/stdc++.h>
# define ll long long

using namespace std;
const ll N = 5e5;
ll m, a[N], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m;
	n = 2 * m + 1;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll i = 1;
	while (i < n) {
		if (a[i] == a[i + 1]) {
			ll j = i;
			while (a[j] == a[j + 1]) j ++;
			i = j + 1;
		}
		else {
			cout << a[i] << endl;
			return 0;
		}
	}
	cout << a[n] << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fc101_once
