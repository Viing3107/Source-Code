# include <bits/stdc++.h>
# define int long long
# define endl "\n"

using namespace std;

const int N = 5e3 + 3;
int n, a[N], pre[N], suf[N], res;

void input(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	res = 0;
}

bool binarySearch(int i, int j){
	int l = i;
	int r = j;
	while (l <= r){
		int m = (l + r) / 2;
		if (pre[j] - pre[m] == pre[m] - pre[i - 1]) return true;
		else if (pre[j] - pre[m] < pre[m] - pre[i - 1]) r = m - 1;
		else l = m + 1;
	}
	return false;
}

void calc(){
	for (int i = 1; i < n; i++){
		for (int j = n; j > i; j--){
			if (binarySearch(i, j)){
				res = max(res, j - i + 1);
				break;
			}
		}
	}
	cout << res << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	init();
	calc();
	
	return 0;
}

// https://oj.vnoi.info/problem/twosum
