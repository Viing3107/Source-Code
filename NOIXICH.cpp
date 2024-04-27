#include <bits/stdc++.h>
#define int long long
#define name "test"

using namespace std;

const int N = 5e5 + 5;
int n, a[N], res;

int solve(int sum, int l){
	if (sum + a[l] >= n - l) return n - l;
	return solve(sum + a[l], l + 1);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);
	cout << solve(0, 1) << endl;

	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}

// https://vn.spoj.com/problems/NOIXICH/