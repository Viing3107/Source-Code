# include <bits/stdc++.h>
# define int long long
# define name "test"

using namespace std;

const int N = 3e2 + 2;
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, x, y, w, a[N][N], res, d[N][N];
bool visited[N][N];

void BFS(int x, int y, int w){
    d[x][y] = w;
    visited[x][y] = true;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()){
        pair<int, int> top = Q.front();
        Q.pop();
        for (int k = 0; k < 8; k++){
            int i1 = top.first + di[k];
            int j1 = top.second + dj[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !visited[i1][j1]){
                if (d[top.first][top.second] - 1 == 0) return;
                d[i1][j1] = d[top.first][top.second] - 1;
                visited[i1][j1] = true;
                Q.push({i1, j1});
            }
        }
    }
}

void input(){
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n >> m;
}

void init(){
    res = 0;
}

void solve(){
    while (m--){
        cin >> x >> y >> w;
        memset(visited, false, sizeof visited);
        memset(d, 0, sizeof d);
        BFS(x, y, w);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) a[i][j] += d[i][j];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) res = max(res, a[i][j]);
}

void output(){
    cout << res << endl;
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

// https://oj.vnoi.info/problem/fc078_boom