// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 1e6 + 5;
const int LIM = 9e5 + 5;

char s[N], t[N];
int MOD, lastDigit, power;
int m2[] = {1, 2, 4, 8};
int m3[] = {1, 3, 9, 7};
int m4[] = {1, 4, 6, 4};
int m7[] = {1, 7, 9, 3};
int m8[] = {1, 8, 4, 2};
int m9[] = {1, 9, 1, 9};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s >> t;
    lastDigit = s[strlen(s) - 1] - '0';
    if (lastDigit == 0 || lastDigit == 1 || lastDigit == 5 || lastDigit == 6) cout << lastDigit;
    else{
        if (strlen(t) == 1) power = (t[0] - '0') % 4;
        else power = ((t[strlen(t) - 2] - '0') * 10 + (t[strlen(t) - 1] - '0')) % 4;
        if (lastDigit == 2) cout << m2[power];
        else if (lastDigit == 3) cout << m3[power];
        else if (lastDigit == 4) cout << m4[power];
        else if (lastDigit == 7) cout << m7[power];
        else if (lastDigit == 8) cout << m8[power];
        else if (lastDigit == 9) cout << m9[power];
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

//
