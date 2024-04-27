# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int N = 1e8 + 8;
vector<int> prime;
int n, ind;
bitset<N> mark;

void sieve(int n){
	for (int i = 4; i <= n; i += 2) mark[i] = 1;
	for (int i = 3; i * i <= n; i += 2) if (!mark[i]){
		for (int j = i * i; j <= n; j += i) mark[j] = 1;
	}
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5; i <= n; i += 6){
		if (!mark[i]) prime.push_back(i);
		if (!mark[i + 2]) prime.push_back(i + 2);
	}
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
}

void init(){
	sieve(N);
}

void solve(){
	while (true){
		cin >> n;
		if (!n) return;
		ind = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
		cout << fixed << setprecision(1) << 100.0 * abs(ind - n / log(n)) / ind << endl;
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

// https://oj.vnoi.info/problem/cprime