# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 4;
int n, k, a[N], preSum[N], res;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
	forUp(i, 1, n, 1) cin >> a[i];
}

void init(){
	res = -1;
	forUp(i, 1, n, 1) preSum[i] = preSum[i - 1] + a[i];
}

void solve(){
	forUp(i, 1, n, 1){
		forDown(j, n, i, -1){
			if(preSum[j] - preSum[i - 1] >= k){
				res = max(res, j - i + 1);
				break;
			}
		}
	}
}

void output(){
	cout << res;
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
	
	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/nkmaxseq