/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:33:25 - 20/06/2024

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

int n, L, result, b[N];
pair<int, int> a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> L;
    forUp(i, 1, n, 1) cin >> a[i].first >> a[i].second;
    int l = 0;
    int r = 1e14;
    while (r - l > 1){
        int m = l + r >> 1;
        int cnt = 0;
        forUp(i, 1, n, 1){
            if (a[i].first >= m) continue;
            int tmp = ceil(1.0 / a[i].second * (m - a[i].first));
            cnt += tmp;
        }
        if (cnt <= L) l = m;
        else r = m;
    }
    cout << l;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc106_garden