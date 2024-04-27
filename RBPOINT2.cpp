# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e5 + 5;
ll n, b[N], r[N], temp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + n + 1);
	b[0] = 1e9;
	for (int i = 1; i <= n; i++) cin >> r[i];	
	sort(r + 1, r + n + 1);
	r[0] = 1e9;
	if (n == 1) cout << abs(b[1] - r[1]) << endl;
	else{
		ll res = 1e9;
		for (int i = 1; i <= n; i++){
			temp = lower_bound(r + 1, r + n + 1, b[i]) - r;
			res = min(res, min(abs(b[i] - r[temp]), abs(b[i] - r[temp - 1])));
			if (res == 0){
				cout << 0 << endl;
				return 0;
			}
		}
		cout << res << endl;
	}
	
	return 0;
} 

// https://oj.vnoi.info/problem/fct027_rbpoint2
