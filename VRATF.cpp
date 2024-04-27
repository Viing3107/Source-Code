# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

int n, k, cnt;
queue<int> Q;

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
}

void init(){
	Q.push(n);
}

void solve(){
	while(!Q.empty()){
		n = Q.front();
		Q.pop();
		if(n - k <= 0 || (n - k) % 2) cnt++;
		else{
			Q.push((n - k) / 2);
			Q.push(n - (n - k) / 2);
		}
	}
}

void output(){
	cout << cnt;
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/vratf