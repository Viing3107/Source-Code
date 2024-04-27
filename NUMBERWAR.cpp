# include <bits/stdc++.h>
# define int long long

using namespace std;

int q, cnt;
string n;

bool isPrime(int n){
	if (n <= 3) return n > 1;
	if (n == 2 || n == 3 || n == 5) return true;
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
	for (int i = 5; i * i <= n; i += 6){
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

bool check(string s){
	if (!isPrime(stoi(s))) return false;
	string tmp = s;
	sort(s.begin(), s.end());
	while (next_permutation(s.begin(), s.end())){
		if (s == tmp) continue;
		if (isPrime(stoi(s))) return true;
	}
	return false;
}

void input(){
	cin >> q;
}

void init(){
	cnt = 0;
}

void solve(){
	while (q--){
		cin >> n;
		cnt += check(n);
	}
}

void output(){
	cout << cnt << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    input();
    init();
    solve();
    output();
    
    return 0;
}

// https://oj.vnoi.info/problem/fc069_numberwars
