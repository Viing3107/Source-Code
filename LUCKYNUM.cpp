# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)

using namespace std;

const int N = 2e2 + 2;
int dp[N][N], q, k, res, x, y, power[N];
queue<pair<int, int>> Q;

void input(){
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
}

void solve(){
    cin >> q;
    while(q--){
        cin >> k;
        power[0] = 1;
        forUp(i, 1, 200, 1) power[i] = (power[i - 1] * 10) % k;
        memset(dp, -1, sizeof dp);
        while(!Q.empty()) Q.pop();
        Q.push({0, 1});
        dp[0][1] = 6 % k;
        Q.push({1, 0});
        dp[1][0] = 8 % k;
        while(!Q.empty()){
            pair<int, int> top = Q.front();
            Q.pop();
            x = top.first;
            y = top.second;
            if(!dp[x][y]){
                forUp(i, 1, x, 1) cout << 8;
                forUp(i, 1, y, 1) cout << 6;
                cout << endl;
                break;
            }
            if(x + y > 200){
                cout << -1 << endl;
                break;
            }
            if(dp[x][y + 1] == -1){
                dp[x][y + 1] = ((dp[x][y] * 10) % k + 6) % k;
                Q.push({x, y + 1});
            }
            if(dp[x + 1][y] == -1){
                dp[x + 1][y] = ((8 * power[x + y]) % k + dp[x][y]) % k;
                Q.push({x + 1, y});
            }
        }
    }
}

void output(){
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    init();
    solve();
    output();

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/luckynum