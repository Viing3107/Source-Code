# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

const int N = 1e5 + 5;
int n, mark[N], x, res;
vector<int> a, b;

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x;
		a.push_back(x);
		mark[x] = 1;
	}
}

void init(){
	for (int i = 1; i <= n * 2; i++){
		if (!mark[i]) b.push_back(i);
	}
	sort(a.begin(), a.end());
	res = 0;
}

void solve(){
	for (auto it : a){
		int ind = upper_bound(b.begin(), b.end(), it) - b.begin();
		while (ind < n && mark[b[ind]]) ind++;
		if (ind < n && !mark[b[ind]]){
			res++;
			mark[b[ind]] = 1;
		}
	}
}

void output(){
	cout << res << endl;
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	init();
	solve();
	output();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc023_highcard