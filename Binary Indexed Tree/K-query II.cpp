/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:59:37 - 27/07/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define ALL(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       BASE        = 311;
const int       BLOCK_SIZE  = 173;
const int       MAX_BLOCK   = 180;
const int       N           = 3e4 + 4;
const int       VAL         = 1e4 + 4;
const int       MOD         = 1e9 + 7;

int n, a[N], q;

/*
gọi cnt[block][val] là số phần tử = val nằm trong khối block
với truy vấn cập nhật a[idx] = oldVal --> a[idx] = newVal
    gọi block là khối chứa a[idx]
    cnt[block][a[idx]]--;
    a[idx] = newVal
    cnt[block][a[idx]]++;
với truy vần tìm số phần tử >= k nằm trong đoạn [l, r]
    gọi blockL là khối chứa l, blockR là khối chứa r
    nếu blockL = blockR: for trâu
    ngược lại:
        với mọi l <= i <= blockL * BLOCK_SIZE: for trâu
        với mọi blockL + 1 <= blockI <= blockR - 1: res += cnt[blockI][k + 1] --> cnt[blockI][1e4] (dùng BIT)
        với mọi (blockR - 1) * BLOCK_SIZE + 1 <= i <= r: for trâu
*/

// BIT + SqrtDecompose
int cnt[MAX_BLOCK][VAL], ft[MAX_BLOCK][VAL];

void update(int block, int idx, int val) {
    for (int i = block; i <= BLOCK_SIZE + 1; i += i & -i) 
        for (int j = idx; j <= 1e4; j += j & -j) ft[i][j] += val;
}

int get(int block, int idx) {
    int res = 0;
    for (int i = block; i; i -= i & -i) 
        for (int j = idx; j; j -= j & -j) res += ft[i][j];
    return res;
}

int get(int blockL, int valL, int blockR, int valR) {
    return get(blockR, valR) - get(blockR, valL - 1) - get(blockL - 1, valR) + get(blockL - 1, valL - 1);
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
    forUp(i, 1, n, 1) cin >> a[i];

    forUp(i, 1, n, 1) update((i - 1) / BLOCK_SIZE + 1, a[i], 1);

    cin >> q;
    while (q--) {
        int type, idx, val, l, r, k;
        cin >> type;
        if (!type) {
            cin >> idx >> val;
            int block = (idx - 1) / BLOCK_SIZE + 1;
            update(block, a[idx], -1);
            a[idx] = val;
            update(block, a[idx], 1);
        }
        else {
            cin >> l >> r >> k;
            int res = 0;
            int blockL = (l - 1) / BLOCK_SIZE + 1, blockR = (r - 1) / BLOCK_SIZE + 1;
            if (blockL == blockR || blockL + 1 == blockR) forUp(i, l, r, 1) res += a[i] > k;
            else {
                forUp(i, l, blockL * BLOCK_SIZE, 1) res += a[i] > k;
                res += get(blockL + 1, k + 1, blockR - 1, 1e4);
                forUp(i, (blockR - 1) * BLOCK_SIZE + 1, r, 1) res += a[i] > k;
            }
            cout << res << endl;
        }
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/kquery2