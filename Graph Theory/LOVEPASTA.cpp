// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N = 5e2 + 2;

int q, n, x, y, z, t;
int di[] = {-1, 1, 0};
int dj[] = {0, 0, 1};
char a[5][N];
bool visited[5][N], check;

void DFS(int i, int j){
    visited[i][j] = true;
    forUp(k, 0, 2, 1){
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (i1 >= 1 && i1 <= 2 && j1 >= 1 && j1 <= n && a[i1][j1] == '*' && !visited[i1][j1]){
            DFS(i1, j1);
            return;
        }
    }
}

void trace(){
    forUp(j, 1, n, 1){
        if (a[1][j] == '*' && a[2][j] == '*'){
            x = 1;
            y = j;
            z = 2;
            t = j;
            return;
        }
        else if (a[1][j] == '*'){
            x = 1;
            y = j;
            return;
        }
        else if (a[2][j] == '*'){
            z = 2;
            t = j;
            return;
        }
    }
}

void ok(){
    forUp(i, 1, 2, 1) forUp(j, 1, n, 1){
        if (a[i][j] == '*' && !visited[i][j]){
            check = false;
            return;
        }
    }
    check = true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--){
        cin >> n;
        check = true;
        forUp(i, 1, 2, 1) forUp(j, 1, n, 1) cin >> a[i][j];
        trace();
        forUp(i, 1, 2, 1) forUp(j, 1, n, 1) visited[i][j] = false;
        DFS(x, y);
        ok();
        if(!check){
            forUp(i, 1, 2, 1) forUp(j, 1, n, 1) visited[i][j] = false;
            DFS(z, t);
        }
        ok();
        cout << (check ? "YES\n" : "NO\n");
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb037_lovepasta
