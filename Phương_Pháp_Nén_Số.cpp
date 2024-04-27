# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"
# define INF 0x3f3f3f3f3f3f
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

// Cho mảng A gồm n phần tử, in ra mảng A sau khi nén số
// Nén số là phương pháp cực tiểu hóa các phần tử mà không làm thay đổi quan hệ lớn bé giữa các phần tử đó

const int N = 1e5 + 5;
int n, a[N], b[N];

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
}

void init(){
	for (int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + n + 1);
}

void solve(){
	for (int i = 1; i <= n; i++){
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
		cout << a[i] << " ";
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

//
