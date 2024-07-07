/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:33:09 - 07/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define eps                     1e-5

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

string s;
double preSum[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    double a = log(10) * (s.length() - 1);
    double res = 0, T = 1;
    for(int i = 0; i < s.length(); i++){
        res += T * (s[i] - '0');
        T /= 10;
    }
    a += log(res);
    // res = s / (10 ^ số mũ cao nhất có thể)
    // VD : s = 6000 -> res = s / (10 ^ 3) = 6
    // VD : s = 123 -> res = s / (10 ^ 2) = 1.23

    // ln(s) = (s.size() - 1) * ln(10) + ln(res) 
    // a = ln(res)

    forUp(i, 1, 100000, 1) preSum[i] = preSum[i - 1] + log(i);

    forUp(i, 1, 100000, 1) {
        int l = i;
        int r = 100000;
        while (r - l >= 0) {
            int m = l + r >> 1;
            if (abs(preSum[m] - preSum[i - 1] - a) <= eps) {
                cout << i << " " << m;
                return (0 ^ 0);
            }
            else if (preSum[m] - preSum[i - 1] < a) l = m + 1;
            else r = m - 1;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/product
