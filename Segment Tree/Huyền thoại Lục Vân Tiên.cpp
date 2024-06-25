/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:20:01 - 25/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 17e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int q, n, k, a[N];

struct SegmentTree{
    int st[4 * N];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return INF;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
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

    cin >> q;
    while (q--) {
        cin >> n >> k;
        forUp(i, 1, n, 1) cin >> a[i];
        it.build(1, 1, n);
        forUp(i, 1, n - k + 1, 1) cout << it.get(1, 1, n, i, i + k - 1) << " ";
        cout << "\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/mink