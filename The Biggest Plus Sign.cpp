// TLE :((

# include <bits/stdc++.h>
# define endl "\n"
# define name "test"
# pragma GCC optimize("Ofast")
# pragma GCC target("avx,avx2,fma")

using namespace std;

const int N = 5e3 + 3;
int n, m, res, x, y, U, D, L, R, di, dj, tmp, temp;
string s;
bitset<N> a[N];

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s;
		for (int j = 1; j <= m; j++){
			if (s[j - 1] - 48) a[i][j] = 1;
		}
	}
}

void init(){
	res = -1;
}

void solve(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i][j]){
				U = D = L = R = 0;
				tmp = 1e9;
				di = i - 1;
				while (a[di][j]){
					U++;
					di--;
				}
				tmp = min(tmp, U);
				di = i + 1;
				while (a[di][j]){
					D++;
					di++;
				}
				tmp = min(tmp, D);
				dj = j - 1;
				while (a[i][dj]){
					L++;
					dj--;
				}
				tmp = min(tmp, L);
				dj = j + 1;
				while (a[i][dj]){
					R++;
					dj++;
				}
				tmp = min(tmp, R);
				if (4 * tmp + 1 > res){
					x = i;
					y = j;
					res = 4 * tmp + 1;
				}
			}
		}
	}
}

void output(){
	cout << res << endl;
	if (res != -1) cout << x << " " << y << endl;
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

// https://oj.vnoi.info/problem/icpc21_mn_j