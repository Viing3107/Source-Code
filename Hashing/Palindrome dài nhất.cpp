#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int N = 5e4 + 4;
const int BASE = 31;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, hashS[N], hashT[N], p[N], result = 1, l, r, m;
string s, t;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rd(int l, int r) {
    return l + (rd() * rd() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
}

int get(const int &l, const int &r, const int arr[]) {
    if (l > r || l < 1 || r > n) return Rd(-INF, INF);
    return ((arr[r] - arr[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> s;
    t = s;
    reverse(t.begin(), t.end());
    s = " " + s;
    t = " " + t;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        hashS[i] = (hashS[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
        hashT[i] = (hashT[i - 1] * BASE + t[i] - 'a' + 1) % MOD;
        p[i] = (p[i - 1] * BASE) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        // Odd Binary Search
        l = 1, r = n;
        while (r - l > 1) {
            m = l + r >> 1;
            if (get(i - m, i - 1, hashS) == get(n - i - m + 1, n - i, hashT)) l = m;
            else r = m;
        }
        result = max(result, 2 * l + 1);

        // Even Binary Search
        l = -1, r = n;
        while (r - l > 1) {
            m = l + r >> 1;
            if (get(i - m, i, hashS) == get(n - i - m, n - i, hashT)) l = m;
            else r = m;
        }
        result = max(result, 2 * l + 2);
    }
    cout << result;

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/paliny?fbclid=IwZXh0bgNhZW0CMTAAAR1974l4kU-vMPkOjWP9igeVxl4pyUFRxe3wSCcRMCbWTGmePutHDJAd5Y0_aem_na6S3Z4X8hGOwuMvHGb0Ag
