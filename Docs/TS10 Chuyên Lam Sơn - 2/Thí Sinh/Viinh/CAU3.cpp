/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:16:04 - 23/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "CAU3"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, position[N], suffixCntM[N], d, result, suffixCntA[N], last = 1e5 + 1;

string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> s;
    s = " " + s;
    forDown(i, n, 1, -1) suffixCntM[i] = suffixCntM[i + 1] + (s[i] == 'M');
    forDown(i, n, 1, -1){
        suffixCntA[i] = suffixCntA[i + 1];
        if (s[i] == 'A') suffixCntA[i] += suffixCntM[i + 1];
    }
    forUp(i, 1, n, 1){
        if (s[i] == 'L') result += suffixCntA[i + 1];
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

// 