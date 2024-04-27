# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int LIM = 1e9;
int q, n, ind;
vector<int> perfect;

void input(){
	if(fopen("test.inp", "r")){
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	}
}

void init(){
	for(int i = 0; i <= 29 && pow(2, i) <= LIM; i++){
		for(int j = 0; j <= 18 && pow(2, i) * pow(3, j) <= LIM; j++){
			for(int k = 0; k <= 12 && pow(2, i) * pow(3, j) * pow(5, k) <= LIM; k++){
				perfect.push_back(pow(2, i) * pow(3, j) * pow(5, k));
			}
		}
	}
	perfect.push_back(LIM);
	perfect.resize(unique(perfect.begin(), perfect.end()) - perfect.begin());
	sort(perfect.begin(), perfect.end());
}

void solve(){
	cin >> q;
	while(q--){
		cin >> n;
		ind = lower_bound(perfect.begin(), perfect.end(), n) - perfect.begin();
		if (perfect[ind] != n) cout << "NO\n";
		else cout << "YES" << " " << ind + 1 << endl;
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

	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc075_numbers