# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int a, b, cnt;
deque<int> u, v;

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> a >> b;
}

void init(){
	while(a){
		u.push_front(a & 1);
		a >>= 1;
	}
	while(b){
		v.push_front(b & 1);
		b >>= 1;
	}
	while(u.size() < v.size()) u.push_front(0);
	while(v.size() < u.size()) v.push_front(0);
	cnt = 0;
}

void solve(){
	while (!u.empty()){
		a = u.front();
		b = v.front();
		cnt += (a != b);
		u.pop_front();
		v.pop_front();
	}
}

void output(){
	if (cnt % 2) cout << -1;
	else cout << cnt / 2;
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

// https://oj.vnoi.info/problem/bedao_m04_change