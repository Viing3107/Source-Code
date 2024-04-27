# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)
# pragma GCC optimize("O2", "O3", "Ofast")
# pragma target("avx", "avx2", "fma")

using namespace std;

struct score{
	int math, it, mathit, index;
};

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 3;
int n, A, B, C, a[N], b[N];
score arr[N];
bool visited[N];
vector<int> v;

bool cmpMath(score a, score b){
	if (a.math == b.math) return a.index < b.index;
	return a.math > b.math;
}

bool cmpIt(score a, score b){
	if (a.it == b.it) return a.index < b.index;
	return a.it > b.it;
}

bool cmpSum(score a, score b){
	if (a.mathit == b.mathit) return a.index < b.index;
	return a.mathit > b.mathit;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n >> A >> B >> C;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
}

void init(){
	for (int i = 1; i <= n; i++){
		arr[i].math = a[i];
		arr[i].it = b[i];
		arr[i].mathit = a[i] + b[i];
		arr[i].index = i;
	}
	memset(visited, false, sizeof visited);
}

void solve(){
	sort(arr + 1, arr + n + 1, cmpMath);
	for(int i = 1; i <= n && A; i++) if (!visited[arr[i].index]){
		v.push_back(arr[i].index);
		visited[arr[i].index] = true;
		A--;
	}
	sort(arr + 1, arr + n + 1, cmpIt);
	for(int i = 1; i <= n && B; i++) if (!visited[arr[i].index]){
		v.push_back(arr[i].index);
		visited[arr[i].index] = true;
		B--;
	}
	sort(arr + 1, arr + n + 1, cmpSum);
	for(int i = 1; i <= n && C; i++) if (!visited[arr[i].index]){
		v.push_back(arr[i].index);
		visited[arr[i].index] = true;
		C--;
	}
	v.resize(unique(v.begin(), v.end()) - v.begin());
	sort(v.begin(), v.end());
}

void output(){
	for (auto it : v) cout << it << endl;
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

// https://oj.vnoi.info/problem/bedao_r10_admissions