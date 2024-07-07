/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:11:51 - 07/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for(int i = (l); i >= (r); i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 55;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, k;
vector<int> adj[N];

struct matrix{
    int a[N][N];

    matrix() {memset(a, 0, sizeof a);}

    friend matrix operator* (matrix u, matrix v) {
        matrix res;
        forUp(i, 1, 50, 1) forUp(j, 1, 50, 1) forUp(k, 1, 50, 1) (res.a[i][j] += u.a[i][k] * v.a[k][j]) %= MOD;
        return res;
    }

    friend matrix operator^ (matrix a, int n) {
        matrix res;
        forUp(i, 1, 50, 1) res.a[i][i] = 1;
        for (; n; n >>= 1, a = a * a) {
            if (n & 1) res = res * a;
        }
        return res;
    }
} A, T;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> k;
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
        int x;
        cin >> x;
        if (x) {
            // hệ số đóng góp của i cho j là 1 -> T.a[i][j] = 1
            // tồn tại cạnh (u, v) -> dp[length][v] += dp[length - 1][u] -> hệ số đóng góp của u cho v là 1 -> T.a[u][v] = 1
            T.a[i][j] = 1;
            A.a[1][j]++;
        }
    }
    A = A * (T ^ (k - 1));
    int result = 0; 
    forUp(i, 1, n, 1) (result += A.a[1][i]) %= MOD;
    cout << result;
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/atcoder_dp_r