# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e3 + 3;
int n, m, k;
map<int, vector<int>> mp;
vector<int> v;

void sinh(int n){
	if (mp.count(n)) return;
	for (int i = 1; i * i <= n; i++){
		if (n % i == 0){
			v.push_back(i);
			int j = n / i;
			if (i != j) v.push_back(j);
		}
	}
	sort(v.begin(), v.end());
	mp[n] = v;
	v.clear();
}

void input(){
	cin >> m;
}

void solve(){
	while (m--){
		cin >> n >> k;
		sinh(n);
		if (mp[n].size() < k) cout << -1 << endl;
		else cout << mp[n][k - 1] << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    input();
    solve();
    
    return 0;
}

// https://oj.vnoi.info/problem/fcc2022q4_prediction
