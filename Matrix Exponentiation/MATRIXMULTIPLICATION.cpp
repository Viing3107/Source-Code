# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e2 + 2;
int q, n, m;

struct matrix{
	int a[N][N];
	
	matrix(){
		forUp(i, 1, N - 1, 1)
			forUp(j, 1, N - 1, 1) a[i][j] = 0;
	}
	friend matrix operator * (matrix a, matrix b){
		matrix res;
		forUp(i, 1, N - 1, 1)
			forUp(j, 1, N - 1, 1)
				forUp(k, 1, N - 1, 1) res.a[i][k] += (a.a[i][j] * b.a[j][k]) % MOD;
		return res;
	}
};

matrix x, y;

matrix binaryExponentiation(matrix a, int b){
	matrix res;
	forUp(i, 1, b, 1) res.a[i][i] = 1;
	while (b){
		if (b & 1) res = res * a;
		b >>= 1;
		a = a * a;
	}
	return res;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	forUp(i, 1, n, 1){
		forUp(j, 1, n, 1) cin >> x.a[i][j];
	}
	cin >> m;
}

void init(){
}

void solve(){
	y = binaryExponentiation(x, m);
	// cout << binaryExponentiation(x, n).a[2][1] << endl;
}

void output(){
	forUp(i, 1, n, 1){
		forUp(j, 1, n, 1) cout << y.a[i][j] << " ";
		cout << endl;
	}
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