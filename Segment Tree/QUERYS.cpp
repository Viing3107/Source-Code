# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int N = 2e5 + 5;
int m, n, q, a[N], st[4 * N], lz[4 * N], type, l, r, x;

void push(int id, int l, int r, int m, int MOD){
	st[id * 2] = (st[id * 2] + lz[id] * (m - l + 1)) % MOD;
	st[id * 2 + 1] = (st[id * 2 + 1] + lz[id] * (r - m)) % MOD;
	lz[id * 2] = (lz[id * 2] + lz[id]) % MOD;
	lz[id * 2 + 1] = (lz[id * 2 + 1] + lz[id]) % MOD;
	lz[id] = 0;
}

void build(int id, int l, int r, int MOD){
	if (l == r){
		st[id] = a[l] % MOD;
		return;
	}
	int m = (l + r) / 2;
	build(id * 2, l, m, MOD);
	build(id * 2 + 1, m + 1, r, MOD);
	st[id] = (st[id * 2] % MOD + st[id * 2 + 1] % MOD) % MOD;
}

void update(int id, int l, int r, int u, int v, int value, int MOD){
	if (r < u || l > v) return;
	if (u <= l && r <= v){
		st[id] = (st[id] + value * (r - l + 1)) % MOD;
		lz[id] = (lz[id] + value) % MOD;
		return;
	}
	int m = (l + r) / 2;
	push(id, l, r, m, MOD);
	update(id * 2, l, m, u, v, value, MOD);
	update(id * 2 + 1, m + 1, r, u, v, value, MOD);
	st[id] = (st[id * 2] % MOD + st[id * 2 + 1] % MOD) % MOD;
}

int get(int id, int l, int r, int u, int v, int MOD){
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return st[id] % MOD;
	int m = (l + r) / 2;
	push(id, l, r, m, MOD);
	int t1 = get(id * 2, l, m, u, v, MOD);
	int t2 = get(id * 2 + 1, m + 1, r, u, v, MOD);
	return (t1 % MOD + t2 % MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> m >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
    
    build(1, 1, n, m);
    while (q--){
		cin >> type >> l >> r;
		if (type == 1){
			cin >> x;
			update(1, 1, n, l, r, x, m);
		}
		else cout << get(1, 1, n, l, r, m) << endl;
	}

    return (0 ^ 0);
}

/*
    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

//
