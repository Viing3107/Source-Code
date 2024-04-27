# include <bits/stdc++.h>
# define ll long long

using namespace std;

ll m, n, t, preSum[222][222], temp[222][222], a[222][222], k, x, y, p, q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n >> t;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++) temp[i][j] = temp[i][j - 1] + a[i][j];
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++) preSum[i][j] = preSum[i - 1][j] + temp[i][j];
	}
	while (t--){
		cin >> x >> y >> p >> q;
		cout << preSum[p][q] - preSum[p][y - 1] - preSum[x - 1][q] + preSum[x - 1][y - 1] << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/fc013_sum2d
