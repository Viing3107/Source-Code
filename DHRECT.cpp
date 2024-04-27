# include <bits/stdc++.h>
# define endl "\n"
# define ll long long

using namespace std;

ll k, n, temp;
map<ll, ll> mp;
priority_queue<pair<ll, ll> > q;
priority_queue<ll> calc;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> k;
	while (k--){
		mp.clear();
		while (!q.empty()) q.pop();
		while (!calc.empty()) calc.pop();
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> temp;
			mp[temp]++;
		}
		for (map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++) q.push(make_pair((*it).second, (*it).first));
		while (!q.empty()){
			pair<ll, ll> top = q.top();
			q.pop();
			if (top.first >= 2){
				calc.push(top.second);
				top.first -= 2;
				q.push(make_pair(top.first, top.second));
			}
			else break;
		}
		if (calc.size() < 2) cout << -1 << endl;
		else{
			ll top1 = calc.top();
			calc.pop();
			ll top2 = calc.top();
			calc.pop();
			cout << 1ll * top1 * top2 << endl;
		}
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/dhrect
