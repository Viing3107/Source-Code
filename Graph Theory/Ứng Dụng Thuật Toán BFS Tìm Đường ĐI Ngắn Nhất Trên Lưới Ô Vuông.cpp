# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e2 + 2;
int r, c, x, y, d[N][N];
char a[N][N];
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

void BFS(int i, int j){
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	a[i][j] = '*';
	d[i][j] = 0;
	while (!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		for (int k = 0; k < 4; k++){
			int i1 = top.first + di[k];
			int j1 = top.second + dj[k];
			if (i1 >= 1 && i1 <= r && j1 >= 1 && j1 <= c && a[i1][j1] != '*'){
				d[i1][j1] = d[top.first][top.second] + 1;
				if (i1 == 1 && j1 == 1) return;
				q.push(make_pair(i1, j1));
				a[i1][j1] = '*';
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	for (int i = 1; i <= r; i++){
		for (int j = 1; j <= c; j++){
			cin >> a[i][j];
			if (a[i][j] == 'C'){
				x = i;
				y = j;
			}
		}
	}
	BFS(x, y);
	cout << d[1][1];
	
	return 0;
}

// https://oj.vnoi.info/problem/vmunch
