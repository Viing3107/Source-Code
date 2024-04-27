# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int MOD =  1000000007;
int n;

int binaryExponentiation(int a, int b){
    int res = 1;
    for (b; b; b >>= 1, a = (a * a) % MOD){
        if (b & 1) res = (res * a) % MOD;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    cout << binaryExponentiation(3, n - 1);

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fcb035_pp3