# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e5 + 5;
int n, x, k, res, ind;
vector<int> boy, girl;

void input(){
    # ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    # endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x > 0) boy.push_back(x);
        else girl.push_back(-x);
    }
}

void init(){
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    res = 0;
}

void solve(){
    for (auto it : girl){
        ind = lower_bound(boy.begin(), boy.end(), it) - boy.begin();
        while (abs(it - boy[ind]) <= k){
            res++;
            ind++;
        }
    }
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
    
	return 0;
}

// https://oj.vnoi.info/problem/fct025_dance