# include <bits/stdc++.h>
# define int long long
# define task "test"
# define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
# define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
# define forEach(it, v) for(typeof(v.begin()) it = v.begin(), _e = v.end(); it != _e; it++)

using namespace std;

const int N = 1e2 + 2;
int n, m, q, u, v, w, dist[N][N], trace[N][N], type;

vector<int> Trace(int u, int v){
    vector<int> path;
    do{
        path.push_back(u);
        u = trace[u][v];
    }while (path.back() != v);
    return path;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    forUp(i, 1, N - 1, 1){
        forUp(j, 1, N - 1, 1) dist[i][j] = 1e9;
        dist[i][i] = 0;
    }

    cin >> n >> m >> q;
    forUp(i, 1, m, 1){
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
        trace[u][v] = v;
        trace[v][u] = u;
    }

    forUp(k, 1, n, 1){
        forUp(u, 1, n, 1){
            forUp(v, 1, n, 1){
                if (dist[u][v] > dist[u][k] + dist[k][v]){
                    dist[u][v] = dist[u][k] + dist[k][v];
                    trace[u][v] = trace[u][k];
                }
            }
        }
    }
    while (q--){
        cin >> type >> u >> v;
        if (!type) cout << dist[u][v] << endl;
        else{
            auto path = Trace(u, v);
            cout << path.size() << " ";
            for (auto it : path) cout << it << " ";
            cout << endl;
        }
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

/*
    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/floyd
