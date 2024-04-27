# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 1e2 + 2;
int n, d, first, last, res;
char a[N][N];
bool check;

void input(){
	# ifndef ONLINE_JUDGE
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	# endif
	cin >> n >> d;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= d; j++) cin >> a[i][j];
	}
}

void init(){
	first = 1;
	res = 0;
}

void solve(){
	for (int j = 1; j <= d; j++){
		check = true;
		for (int i = 1; i <= n; i++){
			if (a[i][j] != 'o'){
				check = false;
				break;
			}
		}
		if (!check){
			last = j - 1;
			res = max(res, last - first + 1);
			first = j + 1;
		}
	}
	if (check) res = max(res, d - first + 1);
}

void output(){
	cout << res << endl;
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

// https://oj.vnoi.info/problem/fc149_vacation