/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:09:55 - 02/06/2024

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

int n, a[N], b[N], c[N], cntB[N], cntC[N], suffix[N], result;

/*
    gọi cntB[i] là số lượng số lớn hơn a[i] nằm trong mảng b
        cntC[i] là số lượng số lớn hơn b[i] nằm trong mảng c
        suffix[i] là cntC[i] + cntC[i + 1] + cntC[i + 2] + ... + cntC[n]
*/

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
    forUp(i, 1, n, 1) cin >> b[i];
    forUp(i, 1, n, 1) cin >> c[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    forUp(i, 1, n, 1) cntC[i] = n - (upper_bound(c + 1, c + n + 1, b[i]) - c) + 1;
    forDown(i, n, 1, -1) suffix[i] = suffix[i + 1] + cntC[i];
    forUp(i, 1, n, 1){
        int idx = upper_bound(b + 1, b + n + 1, a[i]) - b;
        result += suffix[idx];
    }
    cout << result;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc113_tripleinc