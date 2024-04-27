# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

multiset<int> a;
vector<int> b;
int q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> q;
	while (q--){
		int type;
		cin >> type;
		if (type == 1){
			int x;
			cin >> x;
			b.push_back(x);
		}
		else if (type == 2){
			if (!a.empty()){
				cout << *a.begin() << endl;
				a.erase(a.begin());
			}
			else{
				cout << b[0] << endl;
				b.erase(b.begin(), b.begin() + 1);
			}
		}
		else{
			for (vector<int>::iterator it = b.begin(); it != b.end(); it++) a.insert(*it);
			b.clear();
		}
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/bedao_m18_sortqry
