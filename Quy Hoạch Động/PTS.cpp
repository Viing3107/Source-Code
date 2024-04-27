# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forit (it, v) for (typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma")

using namespace std;

// Cho Một Số Nguyên Dương N. Tìm Cách Phân Tích N Thành Tổng Các Số Nguyên Dương
// Lưu Ý : 0 Có 1 Cách Phân Tích Vì 0 Là Tổng Của Dãy Rỗng

const int MOD = 1e9;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int n, dp[N]; // dp[i] : số cách phân tích i thành các số nguyên dương --> dp[n]

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
}

void init(){
	dp[0] = 1;
}

void solve(){
	forUp(i, 1, n, 1){
		forUp(j, i, n, 1) dp[j] = (dp[j] + dp[j - i]) % MOD;
	}
}

void output(){
	cout << dp[n];
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

// 