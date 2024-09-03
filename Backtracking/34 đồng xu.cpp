#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 40;

int t, p, result;
int x[N];
vector<pair<int, int>> L, R;
vector<int> sumL, cntL;

void backtrack(int i, int n, int sum, int cnt, int state) {
    if (i > n) {
        if (!state) L.push_back({sum, cnt});
        else R.push_back({sum, cnt});
        return;
    }
    backtrack(i + 1, n, sum, cnt, state);
    backtrack(i + 1, n, sum + x[i], cnt + 1, state);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    x[1] = 2;
    x[2] = 3;
    x[3] = 5;
    for (int i = 4; i <= 34; i++) x[i] = x[i - 1] + x[i - 2] + x[i - 3];
    // for (int i = 1; i <= 34; i++) cout << x[i] << endl;
    backtrack(1, 17, 0, 0, 0);
    sort(L.begin(), L.end(), [&] (const pair<int, int> &u, const pair<int, int> &v) -> bool {
        return u.first == v.first ? u.second > v.second : u.first < v.first;
    });
    for (auto &x : L) {
        sumL.push_back(x.first);
        cntL.push_back(x.second);
    }
    backtrack(18, 34, 0, 0, 1);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> p;
        result = -1;
        for (auto &x : R) {
            int idx = lower_bound(sumL.begin(), sumL.end(), p - x.first) - sumL.begin();
            if (sumL[idx] + x.first == p) result = max(result, cntL[idx] + x.second);
        }
        cout << "Case #" << i << ": " << result << "\n";
    }
}

// https://oj.vnoi.info/problem/coin34