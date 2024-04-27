# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

const int N = 1e6 + 6;
int n, q, s, a[N], preSum[N], res;

void input(){
// 	freopen(name".inp", "r", stdin);
// 	freopen(name".out", "w", stdout);
}

void init(){
}

void solve(){
	cin >> q;
	while (q--){
		cin >> n >> s;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			preSum[i] = preSum[i - 1] + a[i];
		}
		res = 0;
		for (int i = 1; i <= n; i++) res += (binary_search(preSum + i, preSum + n + 1, preSum[i - 1] + s));
		if (res) cout << res << endl;
		else cout << "HUHU\n";
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc142_zoning