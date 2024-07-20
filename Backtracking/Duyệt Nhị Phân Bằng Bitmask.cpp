# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 22;
int n, a[N], bin[N], i, isFinal, s1, s2, res;

bool isPrime(int n){
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6){
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

void next_perm(){
	int i = n;
	while (i >= 1 && bin[i]){
		bin[i] = 0;
		i--;
	}
	if (!i) isFinal = 1;
	else bin[i] = 1;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	res = -1;
}

void solve(){
	while (!isFinal){
		s1 = 0;
		s2 = 0;
		for (int i = 1; i <= n; i++){
			if (bin[i]) s1 += a[i];
			else s2 += a[i];
		}
		if (isPrime(abs(s1 - s2))) res = max(res, abs(s1 - s2));
		next_perm();
	}
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

// https://oj.vnoi.info/problem/bedao_r02_sister