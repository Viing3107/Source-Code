# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 4 * 5e4;
int stMax[N], stMin[N], a[50005], n, q, l, r;

void build(int id, int l, int r){
	if (l == r){                                            // neu id la nut la
		stMax[id] = stMin[id] = a[l];
		return;
	}
	int m = (l + r) / 2;                                    // phan doan
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	stMax[id] = max(stMax[id * 2], stMax[id * 2 + 1]);      // code 2 tree (co the code 1 tree bang pair)
	stMin[id] = min(stMin[id * 2], stMin[id * 2 + 1]);
} 

int get(int id, int l, int r, int u, int v, string s){
	if (r < u || l > v){                                    // [l, r] va [u, v] khong giao nhau
		if (s == "max") return -1e9;
		else return 1e9;
	}
	if (l >= u && r <= v){                                  // [l, r] la tap con cua [u, v]
		if (s == "max") return stMax[id];
		else return stMin[id];
	}
	int m = (l + r) / 2;                                    // phan doan
	int temp1 = get(id * 2, l, m, u, v, s);
	int temp2 = get(id * 2 + 1, m + 1, r, u, v, s);
	if (s == "max") return max(temp1, temp2);
	else return min(temp1, temp2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--){
		cin >> l >> r;
		int t1 = get(1, 1, n, l, r, "max");
		int t2 = get(1, 1, n, l, r, "min");
		cout << t1 - t2 << endl;
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/nklineup
