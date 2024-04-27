// Tính Số Fibonacci Bằng Phương Pháp Nhân Lũy Thừa Ma Trận

# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

const int MOD = 1e9 + 7;
int n;

struct matrix{
	int a[3][3];
	matrix(){
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j <= 2; j++) a[i][j] = 0;
		}
	}
	friend matrix operator * (matrix a, matrix b){
		matrix res;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= 2; j++)
				for (int k = 1; k <= 2; k++) res.a[i][k] += (a.a[i][j] * b.a[j][k]) % MOD;
		return res;
	}
};

matrix binaryExponentiation(matrix a, int b){
	matrix res;
	res.a[1][1] = res.a[2][2] = 1;
	while (b){
		if (b % 2) res = res * a;
		b /= 2;
		a = a * a;
	}
	return res;
}

matrix res;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n;
}

void init(){
	res.a[1][1] = 0;
	res.a[1][2] = res.a[2][1] = res.a[2][2] = 1;
}

void solve(){

}

void output(){
	cout << binaryExponentiation(res, n).a[2][1] << endl;
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

// https://oj.vnoi.info/problem/errichto_matexp_fibonacci