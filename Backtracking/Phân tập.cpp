#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1ll << 16) + 6;

int n, a[N], result = LLONG_MAX, cnt;
vector<int> L;
map<int, int> mp;

void backtrack(int i, int val, int state) {
    if (!state) {
        if (i * 2 > n) {
            L.push_back(val);
            mp[val]++;
            return;
        }
    }
    else if (i > n) {
        int idx = lower_bound(L.begin(), L.end(), -val) - L.begin();
        if (result > abs(L[idx] + val)) {
            result = abs(L[idx] + val);
            cnt = mp[L[idx]];
        }
        else if (result == abs(L[idx] + val)) cnt += mp[L[idx]];

        if (idx) {
            if (result > abs(L[idx - 1] + val)) {
                result = abs(L[idx - 1] + val);
                cnt = mp[L[idx - 1]];
            }
            else if (result == abs(L[idx - 1] + val)) cnt += mp[L[idx - 1]];
        }
        return;
    }

    backtrack(i + 1, val - a[i], state);
    backtrack(i + 1, val + a[i], state);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    backtrack(1, 0, 0);
    sort(L.begin(), L.end());
    backtrack(n / 2 + 1, 0, 1);
    cout << result << " " << cnt / 2;
}

// https://oj.vnoi.info/problem/lqddiv