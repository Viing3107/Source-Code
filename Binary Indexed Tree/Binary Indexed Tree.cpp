# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e5 + 5;
int m, n, q, h[N], a[N], type, l, r, BIT[N]; // a[i] = abs(h[i] - h[i + 1])

void update(int x, int val){  // build = update * n
	for(; x <= N; x += x & -x) BIT[x] += val;
}

int get(int x){
    int ans = 0;
    for(; x; x -= x & -x) ans += BIT[x];
    return ans;
}

void input(){
	# ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	# endif
	
}

void init(){
	
}

void solve(){
	
}

void output(){
	
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
