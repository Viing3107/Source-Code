/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:31:38 - 05/06/2024

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

int n, l = 0, r = INF, m, result;

int f(int x){
    return x / 3 + x / 5 - x / 15;
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
    while (r - l >= 0){
        m = l + r >> 1;
        if (m >= n + f(m)){
            result = m;
            r = m - 1;
        }
        else l = m + 1;
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

// https://oj.vnoi.info/problem/usaco19ds_moobuzz

// Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtL2IxMTYwYTY4ZmE4YjRlODJhZWEzNzI3ZTM2MmJjNjAyX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF9jM2RlNTMwOC0zZDQ1LTRmYWYtYWQ5OS03NjUzNTI0MWY3MTQ=