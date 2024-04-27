# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

int l, r;

int oddXor(int x){
	if (x % 8 == 1) return x;
	if (x % 8 == 3) return 2;
	if (x % 8 == 5) return x + 2;
	return 0;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> l >> r;
}

void init(){
	if (l % 2 == 0) l++;
	if (r % 2 == 0) r--;
}

void solve(){
}

void output(){
	cout << (oddXor(r) ^ oddXor(max(1ll, l - 2))) << endl;
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

// https://oj.vnoi.info/problem/fcb046_oddxor