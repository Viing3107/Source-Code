# include <bits/stdc++.h>
# define endl "\n"
# define ll long long

using namespace std;

const ll N = 5e4 + 4;
int m, n, st[4 * N], lazy[4 * N];

void update(int id, int l, int r, int x, int y, int z){
	if (r < x || l > y) return;
	if (x <= l && r <= y){
		st[id] += z;
		lazy[id] += z;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, x, y, z);
	update(id * 2 + 1, m + 1, r, x, y, z);
	st[id] = max(st[id * 2], st[id * 2 + 1]) + lazy[id];
}

int get(int id, int l, int r, int x, int y){
	if (r < x || l > y) return -1e9;
	if (x <= l && r <= y) return st[id];
	int m = (l + r) / 2;
	int temp1 = get(id * 2, l, m, x, y);
	int temp2 = get(id * 2 + 1, m + 1, r, x, y);
	return max(temp1, temp2) + lazy[id];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	while (m--){
		int type, x, y;
		cin >> type >> x >> y;
		if (type) cout << get(1, 1, n, x, y) << endl;
		else{
			int z;
			cin >> z;
			update(1, 1, n, x, y, z);
		} 
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/qmax2
