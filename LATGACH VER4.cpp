# include <bits/stdc++.h>
# define long long long
using namespace std;

const long base = 111539786;
map<long, long> F;
long n, t;

long f(long n) {
	if (F.count(n)) return F[n];
	long k = n / 2;
	if (n % 2 == 0) return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % base;
	else return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % base;
}

int main(){
	F[0] = F[1] = 1;
	cin >> t;
	while (t--){
		cin >> n;
		cout << (n == 0 ? 0 : f(n)) << endl;
	}
}

// https://oj.vnoi.info/problem/latgach4