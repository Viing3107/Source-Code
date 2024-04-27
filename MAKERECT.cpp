# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 2e5 + 5;
ll a[N], n, res;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	ll i = 1;
	res = 0;
	while (i <= n - 4){
		if (a[i] == a[i + 1]){
			ll j = i + 2;
			while (j + 1 <= n && a[j] != a[j + 1]) j++;
			if (a[j] == a[j + 1]) {
				res = max(res, a[i] * a[j]);
				i = j + 1;
			}
		}
		i++;
	}
	cout << res;
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb002_makerect
