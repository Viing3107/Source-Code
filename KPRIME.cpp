# include <bits/stdc++.h>
# define maxn 10000007
# define ll long long

using namespace std;

bitset<maxn> prime;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; i++) if (prime[i]) for (int j = i * i; j <= n; j += i) prime[j] = 0;
	ll ans = 0;
	for (int l = 1, r = 0, cnt = 0; l <= n; l++){
		while (r <= n && cnt < k) cnt += prime[++r];
		if (r > n) break;
		ans += n - r + 1;
		cnt -= prime[l];
	}
	cout << ans << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/bedao_g01_kprime
