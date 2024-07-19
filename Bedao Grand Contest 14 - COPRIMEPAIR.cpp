/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:57:13 - 19/07/2024

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

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

/*
    với mọi số dương x : gcd(x, x + 1) = 1
    với mọi số dương lẻ x : gcd(x, x + 2) = 1
    có n + 1 số, mỗi số thuộc [1, 2n] -> theo nguyên lí Dirichlet 
        - giả sử u < v
        - tồn tại 1 cặp (u, v) chỉ khi
            + hoặc v = u + 1
            + hoặc v = u + 2, u lẻ
        - không tồn tại cặp (u, v) chỉ khi
            + u chẵn với mọi u
*/

int n, a[N];

bool check() {
    forUp(i, 1, n, 1) {
        if (a[i] % 2) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    n++;
    forUp(i, 1, n, 1) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (check()) cout << -1;
    else{
        forUp(i, 1, n, 1) {
            if (binary_search(a + 1, a + n + 1, a[i] + 1)){
                cout << a[i] << " " << a[i] + 1;
                return (0 ^ 0);
            }
            if (a[i] % 2 && binary_search(a + 1, a + n + 1, a[i] + 2)) {
                cout << a[i] << " " << a[i] + 2;
                return (0 ^ 0);
            }
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_g14_a