# include <bits/stdc++.h>
# define int long long
# define task "dayso"
# define forit (it, v) for (typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma")

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 5;
int n, k, a[N], dp[4][N], s, maximum[4][N], res;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
}

void init(){
	s = 0;
	res = -INF;
}

void solve(){
	forUp(i, 1, n, 1){
		cin >> a[i];
		s += a[i];
		dp[1][i] = s + maximum[1][i - 1];
		dp[2][i] = s * k + maximum[2][i - 1];
		dp[3][i] = s + maximum[3][i - 1];
		res = max(res, max(dp[1][i], max(dp[2][i], dp[3][i])));
		maximum[1][i] = max(maximum[1][i - 1], -s);
		maximum[2][i] = max(maximum[2][i - 1], max(0ll, dp[1][i]) - s * k);
		maximum[3][i] = max(maximum[3][i - 1], dp[2][i] - s);
	}
}

void output(){
	cout << res << endl;
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
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

// https://oj.vnoi.info/problem/contesttraining_kadanepp
