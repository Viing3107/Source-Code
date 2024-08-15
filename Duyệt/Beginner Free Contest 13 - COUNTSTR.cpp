/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:58:53 - 15/08/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int LOG           = __lg(N) + 5;
const int BLOCK_SIZE    = sqrt(N) + 5;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int n, cnt[N][30], result, idx[N][30];
string s;

/*

gọi idx[i][j] là vị trí của kí tự j gần nhất sau s[i]
result += check(i, idx[i][j]) với mọi 1 <= i <= n, j != s[i]

*/

bool check(int l, int r) {
    return cnt[r - 1][s[l] - 'a' + 1] - cnt[l][s[l] - 'a' + 1] == 0 && cnt[r - 1][s[r] - 'a' + 1] - cnt[l][s[r] - 'a' + 1] == 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> s;
    n = SZ(s);
    s = " " + s;
    forUp(i, 1, n, 1) {
        forUp(j, 1, 26, 1) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a' + 1]++;
    }
    forDown(i, n - 1, 1, -1) {
        forUp(j, 1, 26, 1) idx[i][j] = idx[i + 1][j];
        idx[i][s[i + 1] - 'a' + 1] = i + 1;
    }
    // forUp(i, 1, n, 1) forUp(j, 1, 26, 1) cout << idx[i][j] << " \n"[j == 26];
    forDown(i, n, 1, -1) {
        forUp(j, 1, 26, 1) if (idx[i][j] && j != s[i] - 'a' + 1){
            result += check(i, idx[i][j]);
        }
    }
    cout << result;
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fcb013_countstr