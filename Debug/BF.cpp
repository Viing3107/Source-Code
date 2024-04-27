// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 1e2 + 2;
const int LIM = 1e6 + 6;

int n, m, a[N][N], dp[N][N], key, x, y, res, s, t;
pair<int, int> trace[N][N], tmp;
stack<pair<int, int>> st;

bool inside(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void mark(int value){
    forUp(i, 1, n, 1){
        forUp(j, 1, m, 1){
            if (dp[i][j] == value){
                s = i;
                t = j;
                return;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) cin >> a[i][j];
    forUp(j, 1, m, 1) dp[1][j] = a[1][j];
    forUp(i, 2, n, 1){
        forUp(j, 1, m, 1){
            x = i - 2;
            y = j - 1;
            if (inside(x, y) && dp[x][y] + a[i][j] > dp[i][j]){
                dp[i][j] = dp[x][y] + a[i][j];
                trace[i][j] = {x, y};
            }
            x = i - 2;
            y = j + 1;
            if (inside(x, y) && dp[x][y] + a[i][j] > dp[i][j]){
                dp[i][j] = dp[x][y] + a[i][j];
                trace[i][j] = {x, y};
            }
            x = i - 1;
            y = j - 2;
            if (inside(x, y) && dp[x][y] + a[i][j] > dp[i][j]){
                dp[i][j] = dp[x][y] + a[i][j];
                trace[i][j] = {x, y};
            }
            x = i - 1;
            y = j + 2;
            if (inside(x, y) && dp[x][y] + a[i][j] > dp[i][j]){
                dp[i][j] = dp[x][y] + a[i][j];
                trace[i][j] = {x, y};
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    mark(res);
    while (dp[s][t]){
        st.push({s, t});
        tmp = trace[s][t];
        s = tmp.first;
        t = tmp.second;
    }
    while (!st.empty()){
        cout << st.top().first << " " << st.top().second << endl;
        st.pop();
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 

