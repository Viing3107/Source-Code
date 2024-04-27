# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 1e5 + 5;
int n, b, res, tmp;
pair<int, int> a[N];

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n >> b;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
}

void init(){
	sort(a + 1, a + n + 1);
	res = 0;
}

void solve(){
	for (int i = 1; i <= n; i++){
		tmp = b / a[i].first;
		tmp = min(tmp, a[i].second);
		b -= tmp * a[i].first;
		if (!tmp) break;
		res += tmp;
	}
}

void output(){
	cout << res;
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

// https://oj.vnoi.info/problem/cbuying