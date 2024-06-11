/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:26:24 - 11/06/2024

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

int n, q, preSum[N], preMul[N], l, r;

struct bucket{
    int w, x, mul;
} a[N];

int get(string type, int l, int r){
    return type == "mul" ? (preMul[r - 1] - preMul[l - 1]) : (preSum[r - 1] - preSum[l - 1]);
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
    forUp(i, 1, n, 1){
        cin >> a[i].x >> a[i].w;
        a[i].mul = a[i].x * a[i].w;
        preSum[i] = preSum[i - 1] + a[i].w;
        preMul[i] = preMul[i - 1] + a[i].mul;
    }
    cin >> q;
    while (q--){
        cin >> l >> r;
        cout << a[r].x * get("sum", l, r) - get("mul", l, r) << "\n";
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_r11_h2o

// Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2I2ZjdmZDM1NjJlMjRiYThiZDFlODBmNjBmZmVjMGJiX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF82NzNiOTNmZi0wMDM5LTQ0NmItODc3Zi1iMjM5YTYwMmJlZTU=