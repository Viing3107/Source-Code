/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:51:26 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "CAU4"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a[N], position[N], preSum[N], s, l, r;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    forDown(i, n, 1, -1){
        if (!position[a[i]]) position[a[i]] = i;
    }
    forUp(i, 1, n, 1){
        int tmp = preSum[position[a[i]]] - preSum[i - 1];
        if (tmp > s){
            s = tmp;
            l = i;
            r = position[a[i]];
        }
    }
    cout << s << endl;
    forUp(i, l, r, 1) cout << a[i] << " ";

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 