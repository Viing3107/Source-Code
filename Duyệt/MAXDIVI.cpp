# include <bits/stdc++.h>
# define GCD(a, b) __gcd(a, b)

using namespace std;

const int maxN = 1e6 + 6;
int n, a[maxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 2; i <= n; i++) res = GCD(res, a[i] - a[i - 1]);
	cout << res << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb050_maxdivi
