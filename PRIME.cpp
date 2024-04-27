// code by ving3011
// brute force cuc manh :))
# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e6 + 6;
ll q, eratos[N], pre1[N], pre2[N], pre3[N], pre4[N], pre5[N], pre6[N], pre7[N], a, b, k;
vector<int> prime;
vector<int> lpf;

void sieve(int n){
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    for (int x = 3; x <= n; x += 2){
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i) lpf[prime[i] * x] = prime[i];
    }
}

ll cnt(int n){
	ll res = 0;
	ll temp = 0;
	while (n != 1){
		if (temp != lpf[n]){
			temp = lpf[n];
			res++;
		}
		n /= lpf[n];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sieve(N);
	lpf[0] = 0;
	lpf[1] = 1;
	for (int i = 2; i <= N; i++){
		pre1[i] = pre1[i - 1];
		if (cnt(i) == 1) pre1[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre2[i] = pre2[i - 1];
		if (cnt(i) == 2) pre2[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre3[i] = pre3[i - 1];
		if (cnt(i) == 3) pre3[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre4[i] = pre4[i - 1];
		if (cnt(i) == 4) pre4[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre5[i] = pre5[i - 1];
		if (cnt(i) == 5) pre5[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre6[i] = pre6[i - 1];
		if (cnt(i) == 6) pre6[i]++;
	}
	for (int i = 2; i <= N; i++){
		pre7[i] = pre7[i - 1];
		if (cnt(i) == 7) pre7[i]++;
	}
	cin >> q;
	while (q--){
		cin >> a >> b >> k;
		if (k == 1) cout << pre1[b] - pre1[a - 1] << endl;
		else if (k == 2) cout << pre2[b] - pre2[a - 1] << endl;
		else if (k == 3) cout << pre3[b] - pre3[a - 1] << endl;
		else if (k == 4) cout << pre4[b] - pre4[a - 1] << endl;
		else if (k == 5) cout << pre5[b] - pre5[a - 1] << endl;
		else if (k == 6) cout << pre6[b] - pre6[a - 1] << endl;
		else cout << pre7[b] - pre7[a - 1] << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/bedao_r03_prime
