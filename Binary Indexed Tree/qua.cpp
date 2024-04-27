# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

const int N = 5e5 + 5;
int n, BIT[N], dp[N];
pair<int, int> a[N];

void update(int x, int value){
	for (; x <= n; x += x & -x) BIT[x] = max(BIT[x], value);
}

int get(int x){
	int res = 0;
	for (; x; x -= x & -x) res = max(res, BIT[x]);
	return res;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
}

void init(){
}

void solve(){
	for (int i = 1; i <= n; i++){
		dp[i] = max(dp[i], get(a[i].first - 1) + a[i].second);
		update(a[i].first, dp[i]);
	}
}

void output(){
	cout << *max_element(dp + 1, dp + n + 1) << endl;
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

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/