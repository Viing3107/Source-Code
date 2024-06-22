/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 09:44:02 - 29/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 22;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, mark[N], a[N], isFinal, res = INF;

void nextPermutation(){
    int i;
    for (i = n; i >= 1 && mark[i]; i--) mark[i] = 0;
    if (!i) isFinal = true;
    else mark[i] = 1;
}

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
    while(!isFinal){
        int C = 0;
        int D = 0;
        forUp(i, 1, n, 1){
            if (mark[i]) C += a[i];
            else D += a[i];
        }
        res = min(res, abs(C - D));
        nextPermutation();
    }
    cout << res;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bvh_a