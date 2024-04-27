// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "MATMA"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

string s;
int checkDiv3;
bool checkDiv10;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    for (int i = 0; i <= s.size() - 1 && s.size() >= 1; i++){
        checkDiv3 += s[i] - '0';
        if (s[i] == '0' && !checkDiv10){
            checkDiv10 = true;
            s.erase(s.begin() + i);
            i--;
        }
    }
    if (checkDiv3 % 3 || !checkDiv10){
        cout << -1;
        return (0 ^ 0);
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s << '0';

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/th_thpt_22_c
