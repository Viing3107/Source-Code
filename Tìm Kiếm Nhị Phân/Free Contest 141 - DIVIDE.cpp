/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <iostream>
#include                        <algorithm>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)

using namespace std;

const int       N           = 1e5 + 1;
const long long INF         = 0x3f3f3f3f3f3f3f3f;

int n, a[N], m[5];
long long preSum[N], res = INF, s[5];

long long get(int l, int r) {return preSum[r] - preSum[l - 1];}

void calc() {
    s[1] = get(1, m[1]);
    s[2] = get(m[1] + 1, m[2]);
    s[3] = get(m[2] + 1, m[3]);
    s[4] = get(m[3] + 1, n);
    res = min(res, max({s[1], s[2], s[3], s[4]}) - min({s[1], s[2], s[3], s[4]}));
}

void solve(int type) {
    if (type == 1) {
        m[1] = lower_bound(preSum + 1, preSum + m[2], get(1, m[2]) / 2) - preSum - 2;
        if (m[1] >= 1 && m[1] < m[2]) solve(3);
        m[1]++;
        if (m[1] < m[2]) solve(3);
        m[1]++;
        if (m[1] < m[2]) solve(3);
        m[1]++;
        if (m[1] < m[2]) solve(3);
    }
    else {
        m[3] = lower_bound(preSum + m[2] + 1, preSum + n, preSum[m[2]] + get(m[2] + 1, n) / 2) - preSum - 2;
        if (m[3] > m[2] && m[3] < n) calc();
        m[3]++;
        if (m[3] < n) calc();
        m[3]++;
        if (m[3] < n) calc();
        m[3]++;
        if (m[3] < n) calc();
    }
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
    forUp (i, 1, n, 1) {
        cin >> a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    if (n <= 3) cout << *max_element(a + 1, a + n + 1);
    else {
        m[2] = lower_bound(preSum + 2, preSum + n - 1, get(1, n) / 2) - preSum - 2;
        if (m[2] > 1 && m[2] < n - 1) solve(1);
        m[2]++;
        if (m[2] < n - 1) solve(1);
        m[2]++;
        if (m[2] < n - 1) solve(1);
        m[2]++;
        if (m[2] < n - 1) solve(1);
        cout << res;
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/fc141_divide
