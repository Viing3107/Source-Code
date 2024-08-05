# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 5e4 + 4;
ll m, n, k, a[N], b[N]; 

struct cmp{
	bool operator() (pair<ll, ll> i, pair<ll, ll> j){
		return a[i.first] + b[i.second] > a[j.first] + b[j.second];
	}
};

priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, cmp> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + m + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= m; i++) q.push(make_pair(i, 1));
	while (k--){
		pair<ll, ll> top = q.top();
		q.pop();
		cout << a[top.first] + b[top.second] << endl;
		if (top.second < n){
			top.second++;
			q.push(top);
		}
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/kmin
// https://oj.vnoi.info/problem/fcb034_kthsum
