/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 07:21:49 - 15/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e3 + 3;
const int MOD   = 10;
const int INF   = 0x3f3f3f3f3f3f3f3f;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int t, n;
vector<vector<int>> A(N, vector<int>(N, 0)), B(N, vector<int>(N, 0)), C(N, vector<int>(N, 0));
vector<int> K(N);

int Rd(int l, int r) {
    return (rd() * rd() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

vector<int> multi(vector<int> u, vector<vector<int>> v) {
    vector<int> res(N, 0);
    forUp(i, 1, n, 1) forUp(j, 1, n, 1) (res[i] += u[j] * v[j][i]) %= MOD;
    return res;
}

bool diff(vector<int> u, vector<int> v) {
    forUp(i, 1, n, 1) {
        if (u[i] != v[i]) return true;
    }
    return false;
}

void check() {
    forUp(_, 1, 5, 1) {
        forUp(i, 1, n, 1) K[i] = Rd(0, 9);
        if (diff(multi(K, C), multi(multi(K, A), B))) {    
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> t;
    while (t--) {
        cin >> n;
        forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
        forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
            char c;
            cin >> c;
            B[i][j] = c - '0';
        }
        forUp(i, 1, n, 1) forUp(j, 1, n, 1) {
            char c;
            cin >> c;
            C[i][j] = c - '0';
        }
        check();
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vmatrix