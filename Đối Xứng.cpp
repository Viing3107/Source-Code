// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

int q;
string s;

bool check(string s){ // kiểm tra xem có tồn tại xâu con của s là xâu đỗi xứng không
    forUp(i, 1, s.size() - 1, 1){
        if ((s[i] == s[i - 1]) || (s[i - 1] == s[i + 1])) return true;
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--){
        cin >> s;
        if (s.size() == 1) cout << -1 << endl;
        else if (check(s)) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m23_a