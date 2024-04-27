# include <bits/stdc++.h>
# define int long long
# define name "file"

using namespace std;

const int N = 20;
int q, n, v, a[N][N];

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
}

void init(){

}

void solve(){
	cin >> q;
	while (q--){
		cin >> n >> v;
		memset(a, 0, sizeof a);
		a[1][n] = a[n][1] = 0;
		a[1][1] = v;
		for (int i = 2; i < n; i++) a[i][1] = a[1][i] = a[i - 1][1] / 2;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++){
				if (a[i][j]) continue;
				a[i][j] = a[i - 1][j - 1] - a[i][j - 1];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= i; j++) cout << a[i][j] << " ";
			cout << endl;
		}
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

// https://oj.vnoi.info/problem/fc127_npyramid