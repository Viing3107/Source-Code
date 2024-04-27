# include <bits/stdc++.h>
# define int long long

using namespace std;

int t, n;
map<int, int> mp;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		if (mp.count(n)) cout << mp[n] << endl;
		else{
			int res = 0;
			while (n != 1){
				if (n == 1) break;
				if (n % 2){
					n = (3 * n + 1) / 2;
					res += 2;
				}
				if (n == 1) break;
				if (n % 2 == 0){
					n /= 2;
					res++;
				}
			}
			cout << res << endl;
		}
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb018_gift
