# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll n, a[3][111], x, y;

int main(){
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x >> y;
		a[1][i] = x;
		a[2][i] = y;
	}
	ll res = 0;
	for (int i = 1; i < n; i++){
		for (int j = i + 1; j <= n; j++){
			res = max(res, abs(a[1][i] - a[1][j]) + abs(a[2][i] - a[2][j]));
		}
	}
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb015_mdist
