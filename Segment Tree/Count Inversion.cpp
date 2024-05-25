/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:45:58 - 25/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 6e4 + 4;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], result;

struct SegmentTree{
    int st[4 * N];
    SegmentTree(){
        memset(st, 0, sizeof st);
    }
    void update(int id, int l, int r, int idx){
        if (idx < l || idx > r) return;
        if (l == r){
            st[id]++;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx);
        update(id * 2 + 1, m + 1, r, idx);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} myIt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n;
    forUp(i, 1, n, 1) cin >> a[i];
    forDown(i, n, 1, -1){
        result += myIt.get(1, 1, N, 1, a[i] - 1);
        myIt.update(1, 1, N, a[i]);
    }
    cout << result;

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/nkinv