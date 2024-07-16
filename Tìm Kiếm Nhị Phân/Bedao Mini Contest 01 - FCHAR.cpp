/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:04:44 - 16/07/2024

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

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, m, minLength = INF, cnt[N][30];
string s;

int f(int l, int r) {
    forUp(i, 1, 5, 1) {
        if (cnt[r][i] - cnt[l - 1][i] < m) return false;
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

    cin >> s >> m;
    n = s.size();
    s = " " + s;
    forUp(i, 1, n, 1) {
        forUp(j, 1, 26, 1) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a' + 1]++;
    }
    forDown(i, n - 4, 1, -1) {
        int l = i + 4, r = n, cur = INF;
        while (r - l >= 0) {
            int mid = l + r >> 1;
            if (f(i, mid)) {
                r = mid - 1;
                cur = mid;
            }
            else l = mid + 1;
        }
        minLength = min(minLength, cur - i + 1);
    }
    cout << (minLength >= 1e18 ? -1 : minLength);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/bedao_m01_fchar