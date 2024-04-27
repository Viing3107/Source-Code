# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

int q, x, ind;
string type;
vector<int> a;
double tmp;

bool check(double x){
	return ceil(x) == floor(x);
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

void init(){
}

void solve(){
	cin >> q;
	while (q--){
		cin >> type;
		if (type == "IN"){
			cin >> x;
			ind = lower_bound(a.begin(), a.end(), x) - a.begin();
			a.insert(a.begin() + ind, x);
		}
		else if (type == "OUT"){
			cin >> x;
			ind = lower_bound(a.begin(), a.end(), x) - a.begin();
			a.erase(a.begin() + ind);
		}
		else{
			x = a.size();
			if (x % 2) cout << a[x / 2] << endl;
			else{
				tmp = a[x / 2 - 1] + a[x / 2];
				if (check(tmp)) cout << tmp / 2 << endl;
				else cout << fixed << setprecision(1) << 1.0 / 2.0 * tmp << endl;
			}
		}
	}
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

// https://oj.vnoi.info/problem/icpc22_mb_h