# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N], dp[N], BIT[N];

int get(int u){
    int kq = BIT[u];
    while (u){
        kq = max(kq, BIT[u]);
        u &= (u - 1);  // <==> u -= u & -u
    }
    return kq;
}

void update(int u, int val){
    while (u <= n){
        BIT[u] = max(BIT[u], val);
        u += u & -u;
    }
}


signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++){
        dp[i] = get(a[i] - 1) + b[i];
        update(a[i], dp[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1) << endl;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    
	return 0;
}

// C:\Users\Administrator\Downloads\TI-01-HSG12DT-21-TR9.docx : Bài 1