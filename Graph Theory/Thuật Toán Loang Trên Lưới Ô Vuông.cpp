# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e3 + 3;
int di[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int m, n, k, x, y, color[N][N]; // 0 : trang;     1 : do;      -1 : xanh;

void BFS(int i, int j, int type){
	for (int k = 0; k < 9; k++){
		int i1 = i + di[k];
		int j1 = j + dj[k];
		if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n){
			if (color[i1][j1] == 0){
				color[i1][j1] = type;
				continue;
			}
			if (color[i1][j1] == type) continue;
			if (color[i1][j1] != type){
				color[i1][j1] = 0;
				continue;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n >> k;
	memset(color, 0, sizeof color);
	for (int i = 1; i <= k * 2; i++){
		cin >> x >> y;
		if (i % 2) BFS(x, y, 1);
		else BFS(x, y, -1);
	}
	int red = 0;
	int blue = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (color[i][j] == 1) red++;
			else if (color[i][j] == -1) blue++;
		}
	}
	cout << red << " " << blue << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fcb051_colorball
