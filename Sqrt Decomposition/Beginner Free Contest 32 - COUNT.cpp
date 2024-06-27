/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 16:15:50 - 27/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 2e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;
const int BLOCK_SIZE    = 450;

int n, color[N], tour[N], st[N], en[N], cnt[N], numNode, answer[N];
vector<int> adj[N];

struct query{
    int l, r;

    friend bool operator < (query u, query v){
        return (u.l / BLOCK_SIZE == v.l / BLOCK_SIZE) ? u.r < v.r : u.l < v.l;
    }
} q[N];

void DFS(int u, int par){
    tour[++numNode] = u;
    st[u] = numNode;
    for (auto v : adj[u]) if (v != par) DFS(v, u);
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

    cin >> n;
    forUp(i, 1, n - 1, 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    forUp(i, 1, n, 1) cin >> color[i];
    DFS(1, 0);
    forUp(i, 1, n, 1) q[i] = {st[i], en[i]};
    sort(q + 1, q + n + 1);
    int l = 1, r = 0, result = 0;
    forUp(i, 1, n, 1){
        int u = q[i].l;
        int v = q[i].r;
        while (l < u){
            cnt[color[tour[l]]]--;
            result -= (cnt[color[tour[l]]] == 0);
            l++;
        }
        while (l > u){
            l--;
            result += (cnt[color[tour[l]]] == 0);
            cnt[color[tour[l]]]++;
        }
        while (r < v){
            r++;
            result += (cnt[color[tour[r]]] == 0);
            cnt[color[tour[r]]]++;
        }
        while (r > v){
            cnt[color[tour[r]]]--;
            result -= (cnt[color[tour[r]]] == 0);
            r--;
        }
        answer[tour[u]] = result;
    }
    forUp(i, 1, n, 1) cout << answer[i] << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb032_count