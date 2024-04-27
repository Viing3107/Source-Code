# include <bits/stdc++.h>

using namespace std;

const long long N = 5e5 + 5;
long long res, n, a[N];
stack<pair<long long, long long> > st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	res = 0;
	for (int i = 1; i <= n; i++){
		while (!st.empty() && st.top().first < a[i]){
			res += st.top().second;
			st.pop();
		}
		if (!st.empty()){
			if (st.top().first == a[i]){
				res += st.top().second++;
				if (st.size() > 1) res++;
			}
			else{
				res++;
				st.push(make_pair(a[i], 1));
			}
		}
		else st.push(make_pair(a[i], 1));
	}
	cout << res << endl;

	return 0;
}

// https://oj.vnoi.info/problem/c11pairs
