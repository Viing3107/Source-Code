/*
	Author : Do Quang Vinh
	Kim Son A High School - Ninh Binh
	Created : 00:25:10 - 07/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 100;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int q, n, dp[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	forUp (i, 3, 90, 1) dp[i] = dp[i - 1] + dp[i - 2];
	
	cin >> q;
	while (q--) {
		cin >> n;
		int l = 0, r = 90, result;
		while (r - l >= 0) {
			int m = l + r >> 1;
			if (dp[m + 2] - 1 >= n) {
				result = m;
				r = m - 1;
			}
			else l = m + 1;
		}
		cout << result << "\n";
	}

	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

	return (0 ^ 0);
}

/*

	/\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vnoj_round_01_b