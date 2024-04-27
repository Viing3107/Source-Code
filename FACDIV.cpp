# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

mt19937 rd (chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int n, x, tmp;

int Rd(int l, int r){
    return l + (rd() * rd() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

// Định Lí Wilson : (p + 1)! - 1 % p == 0 khi và chỉ khi p là số nguyên tố
int binaryMultiplication(int a, int b, int MOD){
	int res = 0;
	while(b){
		if(b & 1) res = (res + a) % MOD;
		b >>= 1;
		a = (a + a) % MOD;
	}
	return res;
}

int binaryExponentiation(int a, int b, int MOD){
	int res = 1;
	while(b){
		if(b & 1) res = binaryMultiplication(res, a, n);
		b >>= 1;
		a = binaryMultiplication(a, a, n);
	}
	return res;
}

// nếu n là số nguyên tố thì với mọi i [2, n - 1], n ^ i % n == 1
string FermatCheck(int n){
	bool check = true;
	int lim = min(100ll, n - 1);
	forUp(i, 1, lim, 1){
		tmp = Rd(2, n - 1);
		x = binaryExponentiation(tmp, n - 1, n);
		check = check && (x == 1);
	}
	return (check == true ? "YES\n" : "NO\n");
}

void input(){
	if(fopen("test.inp", "r")){
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
	cin >> n;
}

void init(){
}

void solve(){
	if(n == 2 || n == 3 || n == 5 || n == 7) cout << "YES\n";
	else if (n <= 10) cout << "NO\n";
	else cout << FermatCheck(n);
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

// https://luyencode.net/problem/FACDIV