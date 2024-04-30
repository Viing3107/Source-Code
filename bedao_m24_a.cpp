// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e3 + 3;

string s, t;
map<char, int> mp;
int n;

bool isPalindrome(string s){
    forUp(i, 1, n / 2, 1){
        if (s[i] != s[n - i + 1]) return false;
    }
    return true;
}

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
    if (!isPalindrome(s)) cout << n;
    else{
        forUp(i, 1, n, 1) mp[s[i]]++;
        if (mp.size() == 1) cout << 0;
        else cout << n - 1;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m24_a
