# include <bits/stdc++.h>
# define int long long
# define task "test"
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

const int N = 2e5 + 5;
int n, k, x, maximum, minimum, sum, res, tmp;
priority_queue<int, vector<int>, greater<int>> Q;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> k;
	while (n--){
		cin >> x;
		Q.push(x);
	}
}

void init(){
	res = 0;
}

void solve(){
	while (Q.size() > 1){
		sum = 0;
		for (int i = 1; i <= k && !Q.empty(); i++){
			tmp = Q.top();
			Q.pop();
			sum += tmp;
			if (i == 1) minimum = tmp;
			else if (i == k || Q.empty()) maximum = tmp;
		}
		res += abs(maximum - minimum);
		Q.push(sum);
	}
}

void output(){
	cout << Q.top() << endl << res << endl;
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

// https://oj.vnoi.info/problem/fcb029_replacesum