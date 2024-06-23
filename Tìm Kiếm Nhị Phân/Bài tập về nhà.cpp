/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:06:58 - 23/06/2024

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

int n, q, preSum[N];
pair<int, int> a[N];

bool cmp(pair<int, int> u, pair<int, int> v){
    return u.second < v.second;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    forUp(i, 1, n, 1) preSum[i] = preSum[i - 1] + a[i].first;
    while (q--){
        int x, idx = 0;
        cin >> x;
        int l = 1, r = n;
        while (r - l >= 0){
            int m = l + r >> 1;
            if (a[m].second <= x){
                idx = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        cout << preSum[idx] << "\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/codetour24_c2_a