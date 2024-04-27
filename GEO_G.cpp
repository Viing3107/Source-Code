# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

int xa, ya, xb, yb, xc, yc, A, B, C, scalar;
double dist, AB;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    A = yb - yc;
    B = xc - xb;
    C = xb * yc - xc * yb;
    dist = (abs(A * xa + B * ya + C)) / sqrt(A * A + B * B);
    scalar = (xc - xb) * (xa - xb) + (yc - yb) * (ya - yb);
    AB = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    if (scalar < 0) cout << fixed << setprecision(10) << AB;
    else cout << fixed << setprecision(10) << dist;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/geo_g