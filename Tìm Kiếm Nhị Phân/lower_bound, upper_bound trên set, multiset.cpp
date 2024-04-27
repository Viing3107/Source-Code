# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# pragma GCC optimize("O2")

using namespace std;

int type, x;
multiset<int> ms;

void input(){
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
}

void init(){
	
}

void solve(){
	while (cin >> type){
		if (type == 0) return;
		if (type == 1){
			cin >> x;
			ms.insert(x);
		}
		else if (type == 2){
			cin >> x;
			ms.erase(x);
		}
		else if (type == 3){
			if (ms.empty()) cout << "empty\n";
			else cout << *ms.begin() << endl;
		}
		else if (type == 4){
			if (ms.empty()) cout << "empty\n";
			else cout << *(--ms.end()) << endl;
		}
		else if (type == 5){  // tìm số lớn hơn hoặc bằng x trong set
			cin >> x;
			if (ms.empty()) cout << "empty\n";
			else{
				auto it = ms.upper_bound(x);
				if (it == ms.end()) cout << "no\n";
				else cout << *it << endl;
			}
		}
		else if (type == 6){  // tìm số lớn hơn x trong set
			cin >> x;
			if (ms.empty()) cout << "empty\n";
			else{
				auto it = ms.lower_bound(x);
				if (it == ms.end()) cout << "no\n";
				else cout << *it << endl;
			}
		}
		else if (type == 7){  // tìm số lớn nhất nhỏ hơn x trong set
			cin >> x;
			if (ms.empty()) cout << "empty\n";
			else{
				auto it = ms.lower_bound(x);
				if (it == ms.begin()) cout << "no\n";
				else cout << *(--it) << endl;
			}
		}
		else{                 // tìm số lớn nhất nhỏ hơn hoặc bằng x trong set
			cin >> x;
			if (ms.empty()) cout << "empty\n";
			else{
				auto it = ms.upper_bound(x);
				if (it == ms.begin()) cout << "no\n";
				else cout << *(--it) << endl;
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

	return 0;
}

// https://oj.vnoi.info/problem/cppset