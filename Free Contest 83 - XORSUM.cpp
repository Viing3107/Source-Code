/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:58:01 - 10/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define endl                    "\n"

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n;

/*
    Xét bàng chân lý của XOR :
        0 ^ 0 = 0
        0 ^ 1 = 1
        1 ^ 0 = 1
        1 ^ 1 = 0

    Nhận xét :
        Bản chất phép XOR là phép cộng bit không nhớ, do đó thì để (x xor y) = (x + y) thì x và y phải không tồn tại bit thứ k sao cho (bit thứ k của x) = (bit thứ k của y) = 1
        <=> __builtin_popcountll(x & y) = 0

    Ví dụ :
        x :          x[n - 1] x[n - 2] ... 1 ... x[1] x[0]
        y : y[m - 1] y[m - 2] y[m - 3] ... 1 ... y[1] y[0]
                                    (bit thứ k)
    x ^ y : y[m - 1] ...           [k + 1] 0 ...        
    x + y :                  ([k + 1] + 1) 0 

    Thuật toán :
        Xét từng bit của y :
            Nếu bit thứ i là 0 : Ta có 2 cách chọn bit
            Nếu bit thứ i là 1 : Ta có 1 cách chọn bit

        Sử dụng quy tắc nhân để tính kết quả
*/

int binaryExponentiation(int a, int n) {
    int res = 1;
    for (; n; n >>= 1, a *= a) {
        if (n & 1) res *= a;
    }
    return res;
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
    int BIT_SIZE = 64 - __builtin_clzll(n); // tính phần nguyên trên của log2(n)
    cout << binaryExponentiation(2, (BIT_SIZE - __builtin_popcountll(n)));

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/fc083_xorsum