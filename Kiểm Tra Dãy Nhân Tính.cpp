# include <bits/stdc++.h>
# define int long long
# define name "test"
# pragma GCC optimize ("O2", "O3", "Ofast")
# pragma target ("avx", "avx2", "fma")

using namespace std;

const int N = 1e5 + 5;
int n, a[N];
bool check;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	check = true;
}

void solve(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j * j <= i; j++){
			if (i % j == 0){
				if (a[j] * a[i / j] != a[i]){
					check = false;
					return;
				}
			}
		}
	}
}

void output(){
	cout << (check == true ? "YES" : "NO");
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

// https://oj.vnoi.info/problem/fcb003_nhantinh