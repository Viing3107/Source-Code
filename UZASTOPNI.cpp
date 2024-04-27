# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 15e4 + 4;
int n, a, b;

void input(){
	cin >> n;
}

void solve(){
	for (int i = N; i >= 1; i--){
		a = 2 * n - i * (i + 1);
		b = 2 * (i + 1);
		if (a % b == 0){
			if (a > 0) cout << a / b << " " << a / b + i << endl;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
	
	return 0;
}

// https://oj.vnoi.info/problem/coci1617_r7_uzastopni
