/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:56:23 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 3e4 + 4;
const int LIM           = 1e6 + 6;
const int QUERY_SIZE    = 2e5 + 5;
const int BLOCK_SIZE    = 175;

int n, Q, a[N], u, v, cnt[LIM], result, answer[QUERY_SIZE];

struct query{
    int l, r, id;

    friend bool operator < (query u, query v){
        return (u.l / BLOCK_SIZE == v.l / BLOCK_SIZE) ? u.r < v.r : u.l < v.l;
    }
} q[QUERY_SIZE];


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
    cin >> Q;
    forUp(i, 1, Q, 1){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0;
    forUp(i, 1, Q, 1){
        int u = q[i].l, v = q[i].r;
        while (l < u){
            cnt[a[l]]--;
            result -= (!cnt[a[l]]);
            l++;
        }
        while (l > u){
            l--;
            result += (!cnt[a[l]]);
            cnt[a[l]]++;
        }
        while (r < v){
            r++;
            result += (!cnt[a[r]]);
            cnt[a[r]]++;
        }
        while (r > v){
            cnt[a[r]]--;
            result -= (!cnt[a[r]]);
            r--;
        }
        answer[q[i].id] = result;
    }
    forUp(i, 1, Q, 1) cout << answer[i] << "\n";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/dquery