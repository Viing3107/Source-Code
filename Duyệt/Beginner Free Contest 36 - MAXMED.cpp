/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:13:04 - 14/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 2e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], x, k;

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
    sort(a + 1, a + n + 1);
    forUp(i, 1, n, 1){
        if (i >= (n + 1) / 2) a[i - (n + 1) / 2 + 1] = a[i];
    }
    n = n + 1 >> 1;
    for (int i = 1; i < n; i++){
        int diff = i * (a[i + 1] - a[i]);
        if (k < diff){
            cout << a[i] + k / i;
            return (0 ^ 0);
        }
        a[i] = a[i + 1];
        k -= diff;
    }
    cout << a[n] + k / n;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://hackmd.io/@A-QGjynMR_uo0kpAG-kK8Q/S1thdaYS0
