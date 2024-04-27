# include <bits/stdc++.h>
# define int long long
# define endl "\n"
# define name "test"

using namespace std;

const int N = 2e2 + 2;
int n, m, p, q, s, t, a[N][N], r, c;
bool visited[N][N];
int di[] = {-1, -1, 1, 1};
int dj[] = {-1, 1, -1, 1};
pair<int, int> u;

void BFS(){
	queue<pair<int, int>> Q;
	Q.push({p, q});
	visited[p][q] = true;
	a[p][q] = 0;
	while (!Q.empty()){
		pair<int, int> top = Q.front();
		Q.pop();
		int tmp = a[top.first][top.second];
		for (int k = 0; k < 4; k++){
			u = top;
			while (true){
				u.first += di[k];
				u.second += dj[k];
				if (u.first < 1 || u.first > n || u.second < 1 || u.second > n || visited[u.first][u.second]) break;
				if (a[u.first][u.second] > tmp + 1){
					a[u.first][u.second] = tmp + 1;
					Q.push(u);
				}
			}
		}
	}
	int tmp = a[s][t];
	if (a[s][t] > 1000000) cout << -1 << endl;
	else cout << tmp << endl;
}

void input(){
	freopen(name".inp", "r", stdin);
	freopen(name".out", "w", stdout);
	cin >> n >> m >> p >> q >> s >> t;
	for (int i = 1; i <= m; i++){
		cin >> r >> c;
		visited[r][c] = true;
	}
}

void init(){
	memset(a, 0x3f, sizeof a);  // 0x3f = 63 <==> (1 << 63)
	a[p][q] = 0;
}

void solve(){
	BFS();
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

	return 0;
}

// https://oj.vnoi.info/problem/qbbishop