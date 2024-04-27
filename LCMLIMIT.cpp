# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)
# define gcd(a, b) __gcd(a, b)
# define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int LIM = 1e6;
const int N = 1e3 + 3;
int n, LCM;
vector<int> a;

void input(){
	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
}

void init(){
	a.push_back(1);
	LCM = 1;
	forUp(i, 2, N, 1){
		if(lcm(LCM, i) <= LIM){
			LCM = lcm(LCM, i);
			a.push_back(i);
		}
	}
}

void solve(){
	forUp(i, 0, n - 1, 1) cout << a[i] << " ";
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

	return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fct006_lcmlimit