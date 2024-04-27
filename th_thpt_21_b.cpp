// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "BAI2"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e6 + 6;

string s, t, x, y;
vector<string> u, v;
int res;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    getline(cin, s);
    getline(cin, t);
    for (int i = 0; i <= s.size() - 2 && s.size() >= 2; i++){
        if (s[i] == s[i + 1]){
            s.erase(s.begin() + i);
            i--;
        }
    }
    for (int i = 0; i <= t.size() - 2 && t.size() >= 2; i++){
        if (t[i] == t[i + 1]){
            t.erase(t.begin() + i);
            i--;
        }
    }
    forUp(i, 0, s.size() - 1, 1){
        if (s[i] != ' ') x += s[i];
        else{
            u.push_back(x);
            x = "";
        }
    }
    u.push_back(x);
    forUp(i, 0, t.size() - 1, 1){
        if (t[i] != ' ') y += t[i];
        else{
            v.push_back(y);
            y = "";
        }
    }
    v.push_back(y);
    forUp(i, 0, u.size() - 1, 1) res += u[i] == v[i];
    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/th_thpt_21_b
