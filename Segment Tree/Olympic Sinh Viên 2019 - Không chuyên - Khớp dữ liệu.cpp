/*

    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define gcd(a, b)               __gcd(a, b);

using namespace std;

const int N     = 1e5 + 5;
const int LIM   = 1e6;
const int M     = 78497;

int n, k, st[4 * N], a[N], b[N], d[N], l, r;

void build(int id, int l, int r){
    if (l == r){
        st[id] = d[l];
        return;
    }
    int m = l + r >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = gcd(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
    if (r < u || l > v) return 0;
    if (u <= l && r <= v) return st[id];
    int m = l + r >> 1;
    return gcd(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n, 1) cin >> b[i];
    forUp(i, 1, n, 1) d[i] = abs(a[i] - b[i]);
    build(1, 1, n);
    while (k--){
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/olp_kc19_seq
