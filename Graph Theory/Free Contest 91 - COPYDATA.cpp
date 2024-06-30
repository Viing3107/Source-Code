/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:46:46 - 30/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 3e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, a, b, ans = INF, trace[N], f[N], x, y;
vector<int> adj[N], path;

/*
	f[u] : thời gian nhỏ nhất để thăm hết các con của u
*/

void getPath(int u, int par) {
	for (auto v : adj[u]) {
		if (v == par) continue;
		trace[v] = u;
		getPath(v, u);
	}
}

void dfs(int u, int par, int x) {
	/*
		vector d : mảng chứa thời gian đi thăm của các đỉnh con của u (loại trừ đỉnh x)
		để thời gian đi thăm là nhỏ nhất, ta cần tham lam như sau :
			đỉnh lá có thời gian đi thăm của các đỉnh con là 0
			đỉnh nào có thời gian đi thăm càng lớn càng thì đỉnh cha phải đi thăm nó càng sớm
	*/
	vector<int> d;
	for (auto v : adj[u]) {
		if (v == par || v == x) continue;
		dfs(v, u, x);
		d.push_back(f[v]);
	}
	sort(d.begin(), d.end(), greater<int>());
	f[u] = 0;
	for (int i = 0; i < d.size(); i++) f[u] = max(f[u], d[i] + (i + 1));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> a >> b;
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// vector p : đường đi từ b -> a
	getPath(a, 0);
	for (int u = b; u; u = trace[u]) path.push_back(u);

    // chặt nhị phân
	int l = 1, r = path.size();
	while (l <= r) {
		int m = l + r >> 1;
		x = path[m - 1], y = path[m];
		/*
			bỏ qua cạnh (p[m - 1], p[m])
			ý tưởng là tính riêng từng thành phần liên thông, rồi kết quả là min của max(f[a], f[b]) trong mọi trường hợp
			tuy nhiên, nếu sử dụng vòng for để xét tất cả cạnh (u, v) thuộc đường đi từ b -> a thì dẫn đến TLE
			nhận thấy với mỗi đỉnh i thuộc đường đi từ b -> a thì f[i] đơn điệu nên ta chỉ cần chặt nhị phân tìm cạnh (u, v) thỏa mãn : 
				thời gian đi thăm các đỉnh con của a và b là nhỏ nhất <=> max(f[a], f[b]) là nhỏ nhất
		*/ 
		dfs(a, -1, x);
		dfs(b, -1, y);
        ans = min(ans, max(f[a], f[b]));
		if (f[a] > f[b]) l = m + 1;
		else r = m - 1; 
	}
	cout << ans;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://hackmd.io/@A-QGjynMR_uo0kpAG-kK8Q/S1ZzRcpS0
