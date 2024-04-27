# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 4 * 5e5;
int stMax[N], stMin[N], a[500005], n, q, l, r;

void build(int id, int l, int r){
	if (l == r){                                  
		stMax[id] = stMin[id] = a[l];
		return;
	}
	int m = (l + r) / 2;                  
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	stMax[id] = max(stMax[id * 2], stMax[id * 2 + 1]);   
	stMin[id] = min(stMin[id * 2], stMin[id * 2 + 1]);
} 

int get(int id, int l, int r, int u, int v, string s){
	if (r < u || l > v){                              
		if (s == "max") return -1e9;
		else return 1e9;
	}
	if (l >= u && r <= v){                        
		if (s == "max") return stMax[id];
		else return stMin[id];
	}
	int m = (l + r) / 2;            
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
		if (0ll + t1 - t2 == 0ll + r - l) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}

// https://oj.vnoi.info/problem/bedao_g10_perfect
