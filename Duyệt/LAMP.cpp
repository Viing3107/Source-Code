# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"

using namespace std;

const int N = 1e5 + 5;
int n, q, x, y, a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    while (q--){
        cin >> x >> y;
        a[x]++;
        a[y + 1]--;
    }
    for (int i = 1; i <= n; i++){
        a[i] += a[i - 1];
        cout << a[i] % 2 << " ";
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fct055_lamp