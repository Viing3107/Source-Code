#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

string a, b, res;
int k;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> k >> a >> b;
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        int val = (a[i] - '0') + (b[i] - '0') + carry;
        res = char(val % k + '0') + res;
        carry = val / k;
    }
    if (carry) res = char(carry % k + '0') + res;
    cout << res;

    cerr << "Run Finished";
}

// https://oj.vnoi.info/problem/fc074_fbase
