# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int N = 1e6 + 6;
string s;
int lengthA, lengthB, a[N], b[N], res, ind;
char x, y;

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	getline(cin, s);
	cin >> x >> y;
}

void init(){
	lengthA = lengthB = 0;
	forUp(i, 0, s.size() - 1, 1){
		if(s[i] == x) a[++lengthA] = i + 1;
		if(s[i] == y) b[++lengthB] = i + 1;
	}
}

void solve(){
	forUp(i, 1, lengthA, 1){
		ind = upper_bound(b + 1, b + lengthB + 1, a[i]) - b;
		if(ind <= lengthB) res += lengthB - ind + 1;
	}
}

void output(){
	cout << res;
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

// https://oj.vnoi.info/problem/vmrr