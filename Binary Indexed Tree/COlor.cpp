# pragma GCC optimize("O2")
# pragma GCC target("avx,avx2,fma")
# include <bits/stdc++.h>
# define FOR(i, a, b) for (int i = (a); i <= (b); i++)
# define FOD(i, a, b) for (int i = (a); i >= (b); i--)
# define REP(i, n) for (int i = 0; i < (n); i++)
# define ALL(x) (x).begin(), (x).end()

using namespace std;

const int MAXN = 1e5 + 5;

int N, Q, ans[MAXN];
struct Query{
    int l, r, c;
} q[MAXN];

struct BIT{
    int root[MAXN];
    int get(int u){
        return root[u] == 0 ? u : root[u] = get(root[u]);
    }
    void merge(int u, int v){
        u = get(u); 
        v = get(v);
        if (u == v) return;
        root[u] = v;
    }
    void paint(int l, int r, int c){
        while (true){
            l = get(l);
            if (l > r) break;
            ans[l] = c;
            if (ans[l - 1]) merge(l, l - 1);
            merge(l, l + 1);
            l++;
        }
    }
} mybit;

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    freopen("COLOR.INP","r",stdin);
    freopen("COLOR.OUT","w",stdout);
    cin >> N >> Q;
    FOR(i, 1, Q) cin >> q[i].l >> q[i].r >> q[i].c;
    FOD(i, Q, 1) mybit.paint(q[i].l, q[i].r, q[i].c);
    FOR(i, 1, N) cout << ans[i] << ' ';
    
    return 0;
}

