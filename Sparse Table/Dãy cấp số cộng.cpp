/*
    Author: Do Quang Vinh
    VNU University of Engineering and Technology, Hanoi, Vietnam
    Created: 14:36:21 25/08/2026

*/

#include <bits/stdc++.h>
#define endl "\n"
#define task "test"
#define int long long
#define double long double
#define gcd(x, y) __gcd(x, y)
#define MASK(i) (1ll << (i))
#define SZ(v) (int)(v).size()
#define BIT(i, n) ((n) >> (i) & 1)
#define lcm(x, y) x / gcd(x, y) * y
#define ALL(v) (v).begin(), (v).end()
#define LOG(x) (63 - __builtin_clzll(x))
#define forUp(i, l, r, step) for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step) for (int i = (l); i >= (r); i += step)

using namespace std;

const int LEVEL = 20;
const int BASE = 311;
const int BLOCK_SIZE = 320;
const double EPS = 1e-6;
const int N = 1e5 + 5;
const int VAL = 1e6 + 6;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, q, a[N], d[N], lastPos[N], preSum[N];
map<int, int> mp;

struct SparseTable {
    int gcdVal[N][LOG(N) + 5], lcmVal[N][LOG(N) + 5], minVal[N][LOG(N) + 5], maxVal[N][LOG(N) + 5], maxPos[N][LOG(N) + 5];

    void build() {
        forUp(i, 1, n, 1) {
            gcdVal[i][0] = lcmVal[i][0] = d[i];
            minVal[i][0] = maxVal[i][0] = a[i];
            maxPos[i][0] = lastPos[i];
        }
        for (int j = 1; MASK(j) <= n; j++)
            for (int i = 1; i + MASK(j) - 1 <= n; i++) {
                gcdVal[i][j] = gcd(gcdVal[i][j - 1], gcdVal[i + MASK(j - 1)][j - 1]);
                lcmVal[i][j] = lcm(lcmVal[i][j - 1], lcmVal[i + MASK(j - 1)][j - 1]);
                minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
                maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
                maxPos[i][j] = max(maxPos[i][j - 1], maxPos[i + MASK(j - 1)][j - 1]);
            }
    }

    int getGcd(int l, int r) {
        int k = LOG(r - l + 1);
        return gcd(gcdVal[l][k], gcdVal[r - MASK(k) + 1][k]);
    }

    int getLcm(int l, int r) {
        int k = LOG(r - l + 1);
        return lcm(lcmVal[l][k], lcmVal[r - MASK(k) + 1][k]);
    }

    int getMin(int l, int r) {
        int k = LOG(r - l + 1);
        return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
    }

    int getMax(int l, int r) {
        int k = LOG(r - l + 1);
        return max(maxVal[l][k], maxVal[r - MASK(k) + 1][k]);
    }

    int getMaxPos(int l, int r) {
        int k = LOG(r - l + 1);
        return max(maxPos[l][k], maxPos[r - MASK(k) + 1][k]);
    }
} st;

int getSum(int l, int r) {
    return preSum[r] - preSum[l - 1];
}

string solve(int l, int r) {
    int minVal = st.getMin(l, r), maxVal = st.getMax(l, r);

    // 1. (maxVal - minVal) % (r - l) = 0
    if ((maxVal - minVal) % (r - l)) return "NO";
    int D = (maxVal - minVal) / (r - l);

    // 2. sum(l, r) = (maxVal + minVal) * (r - l + 1) / 2
    if (getSum(l, r) != (maxVal + minVal) * (r - l + 1) / 2) return "NO";

    // 3. max(lastPos[l], .., lastPos[r]) < l
    if (st.getMaxPos(l, r) >= l) return "NO";

    // 4. gcd(d[l + 1], .., d[r]) % D = 0
    if (st.getGcd(l + 1, r) % D) return "NO";
    return "YES";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];

    forUp(i, 1, n, 1) {
        preSum[i] = preSum[i - 1] + a[i];
        d[i] = a[i] - a[i - 1];
        lastPos[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    // forUp (i, 1, n, 1) cout << lastPos[i] << " \n"[i == n];
    st.build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*   /\_/\
    (= ._.)
    />0   \>1
*/

// https://oj.vnoi.info/problem/avlbit