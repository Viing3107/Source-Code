# include <bits/stdc++.h>
# define task "test"
# define int long long
# pragma GCC optimize("O2", "O3", "Ofast", "unroll-loops", "no-stack-protector")
# pragma target("avx", "avx2", "fma")
# define pi M_PI

using namespace std;

int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    cout << (1 << __builtin_popcountll(n));

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/tgpascal