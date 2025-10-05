# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 1e5 + 5, base = 31, MOD = 1e9 + 7;
string s, t;
int q, n, hashS[N], hashT[N], p[N];
bool check;

int getHash(int l, int r, int arr[]){
	return ((arr[r] - arr[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	cin >> q;
}

void calc(){
	for (int i = 1; i < n; i++){
		if (getHash(i, i + 1, hashS) == getHash(n - i, n - i + 1, hashT)){
			check = true;
			return;
		}
	}
}

void solve(){
	while (q--){
		cin >> s;
		t = s;
		n = s.size();
		reverse(t.begin(), t.end());
		s = " " + s;
		t = " " + t;
		p[0] = 1;
		hashS[0] = hashT[0] = 0;
		for (int i = 1; i <= n; i++){
			hashT[i] = (hashT[i - 1] * base + t[i] - 'a' + 1) % MOD;
			hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % MOD;
			p[i] = (p[i - 1] * base) % MOD;
		}
		check = false;
		calc();
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
}

void output(){
	
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc075_evenpal