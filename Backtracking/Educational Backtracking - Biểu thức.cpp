/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof v.begin() it = v.begin(); it != v.end(); it++)

using namespace std;

const int       N           = 1e1 + 1;
const int       MOD         = 1e9 + 7;
const int       BLOCK_SIZE  = sqrt(N) + 5;
const int       INF         = 0x3f3f3f3f3f3f3f3f;
const double    EPS         = 1e-6;

int t, n, m, a[N], sign[N], res;

/*
    sign[i]: dau sau a[i] laf dau gi
    0-->cong
    1-->tru
    2-->nhan

    TRAP: phép nhân có độ ưu tiên cao hơn phép công
    VD: a + b * c thì phải thực hiện b * c trước sau đó thực hiện phép cộng
        thực hiện tuần tự từ trái qua phải --> SAI
*/

void backtrack(int i) {
    if (i == n) {
        int num = a[1];
        forUp (j, 1, n - 1, 1) {
            // xu li truong hop a + b * c * d (uu tien dau nhan truoc)
            int tmp = a[j + 1], step = 0;
            while ((j <= n - 2) && (sign[j + 1] == 2)) {
                (tmp *= a[j + 2]) %= m;
                step++;
                j++;
            }
            if (step) {
                j -= step;
                if (!sign[j]) (num += tmp) %= m;
                else if (sign[j] == 1) (((num -= tmp) %= m) += m) %= m;
                else (num *= tmp) %= m;
                j += step;
            }
            else {
                if (!sign[j]) (num += a[j + 1]) %= m;
                else if (sign[j] == 1) (((num -= a[j + 1]) %= m) += m) %= m;
                else (num *= a[j + 1]) %= m;
            }
        }
        res += !num;
        return;
    }
    forUp (j, 0, 2, 1) {
        sign[i] = j;
        backtrack(i + 1);
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

    cin >> t;
    while (t--) {
        // reset
        res = 0;
        forUp (i, 1, 10, 1) {
            sign[i] = 0;
            a[i] = 0;
        }
        // process
        cin >> n >> m;
        forUp (i, 1, n, 1) {
            cin >> a[i];
            a[i] %= m;
        }
        backtrack(1);
        cout << res << endl;
    }

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 Viing3107

*/

// https://oj.vnoi.info/problem/backtrack_e
