# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 111;
ll n, res, a[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[1] >= 0) cout << a[n] * 2 << endl;
	else if (a[n] <= 0) cout << a[1] * -2 << endl;
	else cout << abs(a[1]) * 2 + abs(a[n]) * 2 << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb003_linetrip
