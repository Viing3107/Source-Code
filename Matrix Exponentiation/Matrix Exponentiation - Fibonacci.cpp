// code by ving3011 - nguoi choi he deo thich matrix exponentiation :)) 
// Tính Số Fibonacci Bằng Phương Pháp Xét Chẵn Lẻ Và Đệ Quy Ghi Nhớ

# include <bits/stdc++.h>
# define long long long

using namespace std;

const long base = 1e9 + 7;
map<long, long> F;
long n;

long solve(long n){
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) return F[n] = (solve(k) * solve(k) + solve(k - 1) * solve(k - 1)) % base;
	else return F[n] = (solve(k) * solve(k + 1) + solve(k - 1) * solve(k)) % base;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	F[0] = F[1] = 1;
	cin >> n;
	cout << (n == 0 ? 0 : solve(n - 1)) << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/errichto_matexp_fibonacci