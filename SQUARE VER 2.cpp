# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

int h[5], w[5];


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    for (int i = 1; i <= 3; i++) cin >> h[i] >> w[i];
    if (h[1] == h[2] && h[2] == h[3] && w[1] + w[2] + w[3] == h[1]) cout << "YES";
    else if (h[2] == h[3] && h[1] == w[2] + w[3] && h[2] + w[1] == h[1]) cout << "YES";
    else if (h[1] == h[2] + h[3] && w[1] + w[2] == h[1]) cout << "YES";
    else if (w[2] == h[3] && h[2] + w[3] == h[1] && w[2] + w[1] == h[1]) cout << "YES";
    else cout << "NO";


    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc040_square