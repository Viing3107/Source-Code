#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"

using namespace std;

const int N = 5e3 + 3;
const int LIM = 1e18 + 18;

int n, a[N], suffix[N], res = -1;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) suffix[i] = max(suffix[i + 1], a[i]);
	for (int i = 1; i + 2 <= n; i++){
		for (int j = i + 1; j + 1 <= n; j++){
			if (a[j] > a[i] && suffix[j + 1] > a[j]) res = max(res, a[i] + a[j] + suffix[j + 1]);
		}
	}

	cout << res;

	return (0 ^ 0);
}