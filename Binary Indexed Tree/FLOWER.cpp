# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forit (it, v) for (typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)

using namespace std;

const int N = 2e5 + 5;
int n, a[N], h[N], BIT[N], dp[N];

void update(int x, int val){
	for (; x <= n; x += x & -x) BIT[x] = max(BIT[x], val);
}

int get(int x){
	int res = 0;
	for (; x; x -= x & -x) res = max(res, BIT[x]);
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
}

void solve(){
	for (int i = 1; i <= n; i++){
		dp[i] = max(dp[i], get(h[i] - 1) + a[i]);
		update(h[i], dp[i]);
	}
}

void output(){
	cout << *max_element(dp + 1, dp + n + 1) << endl;
	cerr << "Time elepsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

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

// https://oj.vnoi.info/problem/atcoder_dp_q