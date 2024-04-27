# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 1e5 + 5;
ll t, n, a[N], s, kanades1, kanades2;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--){
		cin >> n;
		s = 0;
		kanades1 = 0;
		kanades2 = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			kanades1 += a[i];
			kanades2 = max(kanades1, kanades2);
			kanades1 = max(kanades1, 0ll);
			if (a[i] > 0ll) s += a[i];
		}
		sort(a + 1, a + n + 1);
		if (a[n] < 0) s = kanades2 = a[n];
		cout << s << " " << kanades2 << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/fct018_sub
