/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:10:50 - 20/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "BOM"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int q, n, k;

int f(int x){
    x -= x / n;
    return x - k >= 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--){
        cin >> n >> k;
        int result;
        int l = k;
        int r = INF;
        while (r - l >= 0){
            int m = l + r >> 1;
            if (f(m)){
                result = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << result << "\n";
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 