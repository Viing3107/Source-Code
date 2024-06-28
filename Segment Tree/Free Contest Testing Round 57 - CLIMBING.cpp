/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 14:34:06 - 28/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e6 + 6;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, c, a[N];
bool check;

struct SegmentTree{
    pair<int, int> st[4 * N];

    void build(int id, int l, int r){
        if (l == r){
            st[id] = {a[l], a[r]};
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id].first = max(st[id * 2].first, st[id * 2 + 1].first);
        st[id].second = min(st[id * 2].second, st[id * 2 + 1].second);
    }

    pair<int, int> get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return {-INF, INF};
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        pair<int, int> t1, t2;
        t1 = get(id * 2, l, m, u, v);
        t2 = get(id * 2 + 1, m + 1, r, u, v);
        return {max(t1.first, t2.first), min(t1.second, t2.second)};
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

    cin >> n >> m >> c;
    forUp(i, 1, n, 1) cin >> a[i];
    it.build(1, 1, n);
    forUp(i, 1, n - m + 1, 1){
        pair<int, int> tmp = it.get(1, 1, n, i, i + m - 1);
        if (tmp.first - tmp.second <= c){
            check = true;
            cout << i << "\n";
        }
    }
    if (!check) cout << "NONE";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fct057_climbing