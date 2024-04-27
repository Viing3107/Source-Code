#include<bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const ll N = 1e6 + 6;
ll t, n, p[N];

// sang phi ham euler
void sieve(){
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 2; i <= N; i++){
		if(p[i] == i){
			for (int j = i; j <= N; j += i) p[j] -= p[j] / i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	sieve();
	cin >> t;
	while (t--){
		cin >> n;
		cout << p[n] << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/etf