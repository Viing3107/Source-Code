/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:32:57 - 05/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], l, r, x, type;

struct wrongInfomation{
    int l, r, val;
} query[N];

struct SegmentTree{
    int st[4 * N], lazy[4 * N];

    void push(int id, int l, int r, int m){
        st[id * 2] += (m - l + 1) * lazy[id];
        st[id * 2 + 1] += (r - m) * lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    void build(int id, int l, int r){
        if (l == r){
            st[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (r < u || l > v) return;
        if (u <= l && r <= v){
            st[id] += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        int m = l + r >> 1;
        push(id, l, r, m);
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        push(id, l, r, m);
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
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
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    forUp(i, 1, q, 1){
        cin >> type;
        if (type == 1){
            cin >> query[i].l >> query[i].r >> query[i].val;
            it.update(1, 1, n, query[i].l, query[i].r, query[i].val);
        }
        else if (type == 2){
            cin >> x;
            query[i] = query[x];
            query[i].val *= -1;
            it.update(1, 1, n, query[i].l, query[i].r, query[i].val);
        }
        else{
            cin >> l >> r;
            cout << it.get(1, 1, n, l, r) << endl;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g11_easyquery