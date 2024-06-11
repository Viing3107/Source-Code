/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:35:08 - 11/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;
const int BLOCK_SIZE    = 320;

int result, n, m, a[N], st[N], en[N], numNode, tour[N], answer[N], cnt[N];
vector<int> adj[N];

struct query{
    int l, r;

    friend bool operator < (query u, query v){
        if (u.l / BLOCK_SIZE == v.l / BLOCK_SIZE) return u.r < v.r;
        return u.l < v.l;
    }
} q[N];

void DFS(int u, int par){
    tour[++numNode] = u;
    st[u] = numNode;
    for (auto v : adj[u]){
        if (v == par) continue;
        DFS(v, u);
    }
    en[u] = numNode;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    forUp(i, 1, n, 1) q[i] = {st[i], en[i]};
    sort(q + 1, q + n + 1);
    int l = 1, r = 0;
    forUp(i, 1, n, 1){
        int u = q[i].l;
        int v = q[i].r;
        while (r < v){
            r++;
            if (!cnt[a[tour[r]]]) result++;
            cnt[a[tour[r]]]++;
        }
        while (l > u){
            l--;
            if (!cnt[a[tour[l]]]) result++;
            cnt[a[tour[l]]]++;
        }
        while (r > v){
            cnt[a[tour[r]]]--;
            if (!cnt[a[tour[r]]]) result--;
            r--;
        }
        while (l < u){
            cnt[a[tour[l]]]--;
            if (!cnt[a[tour[l]]]) result--;
            l++;
        }
        answer[tour[u]] = (result == m);
    }
    forUp(i, 1, n, 1) cout << answer[i];
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb028_agrtree