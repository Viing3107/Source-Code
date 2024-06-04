/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:03:53 - 04/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, cnt, degree[N];
map<string, int> mp;
vector<int> adj[N];
queue<int> Q;
bool visited[N];

struct edge{
    string u, v;
    char sign;
} mark[N];

void kahn(){
    forUp(i, 1, cnt, 1){
        if (!degree[i]) Q.push(i);
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        visited[u] = true;
        for (auto v : adj[u]){
            degree[v]--;
            if (!degree[v]) Q.push(v);
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

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> mark[i].u >> mark[i].sign >> mark[i].v;
        if (!mp.count(mark[i].u)) mp[mark[i].u] = ++cnt;
        if (!mp.count(mark[i].v)) mp[mark[i].v] = ++cnt;
    }
    forUp(i, 1, n, 1){
        if (mark[i].sign == '>'){
            adj[mp[mark[i].u]].push_back(mp[mark[i].v]);
            degree[mp[mark[i].v]]++;    
        }
        else{
            adj[mp[mark[i].v]].push_back(mp[mark[i].u]);
            degree[mp[mark[i].u]]++; 
        }
    }
    kahn();
    forUp(i, 1, cnt, 1){
        if (!visited[i]){
            cout << "impossible";
            return (0 ^ 0);
        }
    }
    cout << "possible";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc036_dwarves