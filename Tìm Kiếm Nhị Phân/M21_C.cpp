# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5;
int n, k, a[N], l, r, m, res;

int f(int m){
	int res = 0;
	forUp(i, 1, n, 1) res += ceil(1.0 / m * a[i]) - 1;
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
	forUp(i, 1, n, 1) cin >> a[i];
}

void init(){
	l = 1;
	r = 1e10;
}

void solve(){
	while(r - l >= 0){
		m = (l + r) / 2;
		if (f(m) <= k){
			res = m;
			r = m - 1;
		}
		else l = m + 1;
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

// https://oj.vnoi.info/problem/bedao_m21_c