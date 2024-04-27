# include <bits/stdc++.h>
# define int long long
# define task "hcn"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e2 + 2;
int n, m, res, dp[N][N];

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

void init(){
}

void solve(){
	while(cin >> n >> m){
		memset(dp, 0, sizeof dp);
		forUp(i, 1, n, 1){
			forUp(j, 1, m, 1){
				if(i == j){
					dp[i][j] = 1;
					continue;	
				}
				dp[i][j] = INF;
				forUp(k, 1, i - 1, 1) dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
				forUp(k, 1, j - 1, 1) dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
			}
		}
		cout << dp[n][m] << endl;
	}
}

void output(){
	
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