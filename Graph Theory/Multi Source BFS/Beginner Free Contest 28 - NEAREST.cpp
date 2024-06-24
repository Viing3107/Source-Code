/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:33:17 - 24/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 5e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, b, r, u, v, A[N], B[N], answer[N];
vector<int> adj[N];
queue<int> Q;
bool visited[N];

void BFS(){
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                answer[v] = answer[u] + 1;
                Q.push(v);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> b >> r;
    forUp(i, 1, b, 1){
        cin >> A[i];
        visited[A[i]] = true;
        Q.push(A[i]);
    }
    forUp(i, 1, r, 1) cin >> B[i];
    forUp(i, 1, m, 1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS();
    forUp(i, 1, r, 1) cout << answer[B[i]] << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb028_nearest