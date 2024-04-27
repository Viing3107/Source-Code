// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 2e5 + 5;
const int LIM = 9e5 + 5;
const int MOD = 1e3 + 7;

map<int, int> F;
int n, q, type, l, r, k, st[4 * N], lazy[4 * N], pisano[110];

int f(int n){
    if (F.count(n)) return F[n];
    int k = n / 2;
    if (n & 1) return F[n] = (f(k + 1) * f(k) + f(k) * f(k - 1)) % MOD;
    return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % MOD;
}

int fibo(int n){
    return (!n ? 0 : f(n - 1));
}

int modulo(int n){
    if (n % 108) return n % 108;
    return 108;
}

void push(int id, int l, int r, int m){
    st[id * 2] = (st[id * 2] + lazy[id] * (m - l + 1));
    st[id * 2 + 1] += lazy[id] * (r - m);
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] +=lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int value){
    if (r < u || l > v) return;
    if (u <= l && r <= v){
        st[id] += value * (r - l + 1);
        lazy[id] += value;
        return;
    }
    int m = l + r >> 1;
    push(id, l, r, m);
    update(id * 2, l, m, u, v, value);
    update(id * 2 + 1, m + 1, r, u, v, value);
    st[id] = (st[id * 2] + st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return st[id];
    int m = l + r >> 1;
    push(id, l, r, m);
    return (get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    F[0] = F[1] = 1;

    forUp(i, 1, 108, 1) pisano[i] = fibo(i);

    cin >> n >> q;
    while(q--){
        cin >> type >> l >> r;
        if (type == 1){
            cin >> k;
            update(1, 1, n, l, r, pisano[modulo(k)]);
        }
        else cout << get(1, 1, n, l, r) << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/hcm_thpt_22_b
// Bài có sử dụng kiến thức về Chu Kỳ Pisano : https://vi.wikipedia.org/wiki/Chu_k%E1%BB%B3_Pisano