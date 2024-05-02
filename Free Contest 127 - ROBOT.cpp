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

const int N = 1e2 + 2;

int n, m, k, a[N][N], presentMove[N][N], x = 1, y = 1, cnt, element, cycleLength, newK;
bool visited[N][N];
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

bool inside(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
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
    forUp(i, 1, n, 1) forUp(j, 1, m, 1) cin >> a[i][j];
    cin >> k;
    while (k && !visited[x][y]){
        visited[x][y] = true;
        presentMove[x][y] = ++cnt;
        element = a[x][y];
        if (inside(x + di[element], y + dj[element])){
            x += di[element];
            y += dj[element];
        }
        else{
            cout << x << " " << y;
            return (0 ^ 0);
        }
        k--;
    }
    if (!k) cout << x << " " << y;
    else{
        newK = k % (cnt - presentMove[x][y] + 1);
        forUp(i, 1, newK, 1){
            element = a[x][y];
            x += di[element];
            y += dj[element];
        }
        cout << x << " " << y;
    }

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc127_robot
