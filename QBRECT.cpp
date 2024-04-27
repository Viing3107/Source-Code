# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for (typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for (int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for (int variable = start; variable >= end; variable += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 3;
int n, m, l[N], r[N], h[N], res, a[N][N];

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> m;
	forUp(i, 1, n, 1)
		forUp(j, 1, m, 1) cin >> a[i][j];
}

void init(){
	res = -INF;
}

void solve(){
	forUp(i, 1, n, 1){
		forUp(j, 1, m, 1){
			if(a[i][j]) h[j]++;
			else h[j] = 0;
		}
		h[0] = h[m + 1] = -1;
		forUp(j, 1, m, 1){
			l[j] = j;
			while(h[l[j] - 1] >= h[j]) l[j] = l[l[j] - 1];
		}
		forDown(j, m, 1, -1){
			r[j] = j;
			while(h[r[j] + 1] >= h[j]) r[j] = r[r[j] + 1];
		}
		forUp(j, 1, m, 1) res = max(res, h[j] * (r[j] - l[j] + 1));
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

// https://oj.vnoi.info/problem/qbrect