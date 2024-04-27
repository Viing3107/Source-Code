# include <bits/stdc++.h>
# define int unsigned long long
# define task "test"

using namespace std;

const int N = 1e2 + 2;
int n, a[N], m, x, k, res = 0, mark[N];
vector<int> b[N];
bool check;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> k;
        for (int j = 1; j <= k; j++){
            cin >> x;
            b[i].push_back(x);
        }
        sort(b[i].begin(), b[i].end());
    }

    for (int j = 1; j <= m; j++){
        check = true;
        for (int i = 1; i <= n && check; i++){
            if (binary_search(b[j].begin(), b[j].end(), a[i])) check = false;
        }
        if (check) res++;
    }

    cout << res;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/coci2021_r4_pizza