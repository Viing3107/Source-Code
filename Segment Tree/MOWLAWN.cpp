# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
int n, k, a[N], dp[N], st[4 * N], sum;
deque<int> Q;

void update(int id, int l, int r, int index, int value){
	if(index < l || index > r) return;
	if(l == r){
		st[id] = value;
		return;
	}
	int m = (l + r) / 2;
	update(id * 2, l, m, index, value);
	update(id * 2 + 1, m + 1, r, index, value);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if(l > v || r < u) return INF;
	if(u <= l && r <= v) return st[id];
	int m = (l + r) / 2;
	return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

// O(nlogn)
void solve(){  // sử dung Segment Tree để tìm tim trên đoạn đọ dài k
	forUp(i, 1, k, 1){
		dp[i] = a[i];
		update(1, 1, n, i, dp[i]);
	}
	forUp(i, k + 1, n + 1, 1){
		dp[i] = get(1, 1, n, i - k, i - 1) + a[i];
		update(1, 1, n, i, dp[i]);
	}

	cout << sum - dp[n + 1];
}

// O(n)
void solve2(){  // sử dụng kĩ thuật Sliding Window Minimum để tìm min trên đoạn độ dài k
	Q.push_back(0);
    forUp(i, 1, n + 1, 1){
        while (!Q.empty() && Q.front() < i - k) Q.pop_front();
        dp[i] = dp[Q.front()] + a[i];
        while (!Q.empty() && dp[Q.back()] >= dp[i]) Q.pop_back();
        Q.push_back(i);
    }

    cout << sum - dp[n + 1];
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	cin >> n >> k;
	k++;
	forUp(i, 1, n, 1){
		cin >> a[i];
		sum += a[i];
	}
	solve();

	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fct029_mowlawn
// Solution : C:\Users\Administrator\Desktop\Tai Lieu Hoc Sinh.docx : Thằng Bờm