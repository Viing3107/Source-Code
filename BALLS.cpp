# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"

using namespace std;

const int N = 2e5 + 5;
int n, a[N], res, tmp;
map<int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    for (auto it : mp) res += it.second * (it.second - 1) / 2;
    for (int i = 1; i <= n; i++){
        tmp = res - mp[a[i]] * (mp[a[i]] - 1) / 2;
        tmp += (mp[a[i]] - 1) * (mp[a[i]] - 2) / 2;
        cout << tmp << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fc123_balls