/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:06:24 - 18/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "DIENPHIEU"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5e4 + 4;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, w[N], l, r;

struct SegmentTree{
    int st[4 * N];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = w[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return -INF;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }
} it;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> w[i];
    it.build(1, 1, n);
    while (q--){
        cin >> l >> r;
        cout << it.get(1, 1, n, l, r) << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 