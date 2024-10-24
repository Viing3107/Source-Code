/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 15:13:44 - 24/10/2024

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define BIT(i, n)               (n >> i & 1)
#define SZ(v)                   (int) v.size()
#define all(v)                  v.begin(), v.end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(), _e = it.end(); it != _e; it++)

using namespace std;

const int       N           = 1e2 + 2;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int t;

struct BigNum {
    string s;

    BigNum() {
        s = "";
    }

    friend istream &operator >> (istream &stream, BigNum &u) {
        stream >> u.s;
        return stream;
    }

    friend BigNum operator + (BigNum u, BigNum v) {
        while (SZ(u.s) < SZ(v.s)) u.s = '0' + u.s;
        while (SZ(v.s) < SZ(u.s)) v.s = '0' + v.s;
        BigNum res;
        int carry = 0;
        forDown(i, SZ(u.s) - 1, 0, -1) {
            int val = (u.s[i] - '0') + (v.s[i] - '0') + carry;
            res.s = char(val % 10 + '0') + res.s;
            carry = val / 10;
        }
        if (carry) res.s = '1' + res.s;
        return res;
    }

    friend BigNum operator * (const BigNum &u, const int &n) { // Nhân số lớn với một số < 10
        BigNum res;
        int carry = 0;
        forDown(i, SZ(u.s) - 1, 0, -1) {
            int val = (u.s[i] - '0') * n + carry;
            res.s = char(val % 10 + '0') + res.s;
            carry = val / 10;
        }
        if (carry) res.s = char(carry + '0') + res.s;
        return res;
    }

    friend BigNum div2 (const BigNum &u) { // Chia số lớn cho 2
        BigNum res;
        int carry = 0;
        forUp(i, 0, SZ(u.s) - 1, 1) {
            int val = carry * 10 + (u.s[i] - '0');
            res.s += char(val / 2 + '0');
            carry = val % 2;
        }
        res.s.erase(0, res.s.find_first_not_of('0'));
        if (res.s.empty()) res.s = "0";
        return res;
    }
} p[N], n, res;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    p[0].s = "1";
    forUp(i, 1, 64, 1) p[i] = p[i - 1] * 3;

    cin >> t;
    while (t--) {
        res.s = "0";
        cin >> n;
        forUp(i, 0, 64, 1) {
            if ((n.s.back() - '0') & 1) res = res + p[i];
            n = div2(n);
        }
        cout << res.s << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/treenum