# include <bits/stdc++.h>
# define int long long

using namespace std;

const int N = 5e5 + 5;
int n, a[N], w[N], dp[N], Sum[N];

struct IT{
    int t[N * 4];
    int id[N];
    void init(int node, int l, int r){
        t[node] = -1e18;
        if (l == r){
            id[l] = node;
            return;
        }
        int mid = l + r >> 1;
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
    }
    void update(int pos, int val){
        int node = id[pos];
        if (t[node] >= val) return;
        t[node] = val;
        node >>= 1;
        while(node){
            t[node] = max(t[node << 1], t[node << 1 | 1]);
            node >>= 1;
        }
    }
    int get(int id, int l, int r, int u, int v){
        if (r < u || l > v) return -1e18;
        if (u <= l && r <= v) return t[id];
        int mid = l + r >> 1;
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
} it;

void sub1(){
    for (int i = 1; i <= n; i++) Sum[i]=0;
    for (int i = 1; i <= n; i++){
        int sm = 0;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i] && sm < Sum[j]) sm = Sum[j];
        Sum[i] = sm + w[i];
    }
    cout << *max_element(Sum + 1, Sum + n + 1) << endl;
}

void sub2(){
    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= n; i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    int m = v.size();
    it.init(1, 1, m);
    for(int i = 1; i <= n; i++){
        dp[i] = w[i];
        dp[i] = max(dp[i], it.get(1, 1, m, 1, a[i] - 1) + w[i]);
        it.update(a[i], dp[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    freopen("QUA.INP", "r", stdin);
    freopen("QUA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> w[i];
    sub1();
    //sub2();

    return 0;
}