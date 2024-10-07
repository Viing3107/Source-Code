#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

int n;
string s;
vector<int> cnt(27, 0);

ostream &operator << (ostream &stream, const vector<int> &v) {
    string s, t;
    int pos = 0;
    for (int i = 1; i <= 26; i++) {
        if (v[i]) {
            if (v[i] & 1) pos = i;
            char c = char(i + 'a' - 1);
            for (int j = 1; (j << 1) <= v[i]; j++) {
                s = s + c;
                t = c + t;
            }    
        }
    }
    if (pos) s += char(pos + 'a' - 1);
    stream << s << t;
    return stream;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) cnt[s[i] - 'a' + 1]++;
    int oddCnt = 0;
    for (int i = 1; i <= 26; i++) oddCnt += cnt[i] & 1;
    int i = 1, j = 26;
    while (oddCnt > 1 && i < j) {
        while (i < j && !(cnt[i] & 1)) i++;
        while (i < j && !(cnt[j] & 1)) j--;
        if (i < j) {
            cnt[i]++;
            cnt[j]--;
            oddCnt -= 2;
        }
    }
    cout << cnt;
}

// https://oj.vnoi.info/problem/cf_edu2c