# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)
# define it *itr

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int LIM = 5e1 + 1;
string s, t;
int n, cnt;

// Tính Chất : Một Số Có k Chữ Số Cuối Cùng Chia Hết Cho 2^k Thì Số Đó Chia Hết Cho 2^k

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> s;
}

void init(){
	n = s.size();
	s = " " + s;
	cnt = 0;
}

void solve(){
	forUp(i, 1, n, 1) cnt += ((s[i] - '0') % 4 == 0);
	forUp(i, 2, n, 1){
		t = s.substr(i - 1, 2);
		if(stoll(t) % 4 == 0) cnt += i - 1;
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
	
	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc119_fmultiples