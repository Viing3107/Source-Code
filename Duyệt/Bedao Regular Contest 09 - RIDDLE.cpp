#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, pos[30], cnt[N][30], result;
string s;

bool check(int l, int r) {
    if (l >= r) return false;
    if (r - l == 1) return true;
    for (int i = 1; i <= 26; i++) if (i != s[l] - 'a' + 1) {
        if (cnt[r - 1][i] - cnt[l][i] == r - l - 1) return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 26; j++) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a' + 1]++;
    }
    for (int i = n; i >= 1; i--) {
        result += check(i, pos[s[i] - 'a' + 1]);
        pos[s[i] - 'a' + 1] = i;
    }
    cout << result;
}

// https://oj.vnoi.info/problem/bedao_r09_riddle