/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 22:31:29 - 23/07/2025

*/

#include                        <iostream>
#define endl                    "\n"
#define task                    "test"
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)

using namespace std;

const int       N           = 25e4 + 4;
const int       VAL         = 5e4 + 4;
const int       BLOCK_SIZE  = 500;
const int       MAX_BLOCK   = 502;

int n, a[N], q;

/*
gọi cnt0[i][val] là số lượng số có giá trị val đứng trước a[i]
gọi cnt1[i][val] là số lượng số có giá trị val đứng sau a[i]
đầu tiên, đếm số cặp nghịch thế (BIT/IT cơ bản), đặt là R
Ý tưởng ngây thơ:
với mỗi truy vấn thay a[idx] = oldVal --> a[idx] = newVal,
    R = R - tổng(cnt0[idx][a[idx] + 1] -> cnt0[idx][5e4]) - tổng(cnt1[idx][1] -> cnt1[idx][a[idx] - 1])
    a[idx] = newVal;
    R = R + tổng(cnt0[idx][a[idx] + 1] -> cnt0[idx][5e4]) + tổng(cnt1[idx][1] -> cnt1[idx][a[idx] - 1])

Cải tiến:
để làm nhanh thao tác này, ta cần chia n phần tử thành sqrt(n) đoạn
gọi cnt[block][val] là số lượng số có giá trị val nằm trong khối block
với mỗi truy vấn thay a[idx] = oldVal --> a[idx] = newVal,
    gọi block là khối chứa a[idx]

    với mọi blockI < block: R -= tổng(cnt[blockI][a[idx] + 1] -> cnt[blockI][5e4]) (dùng BIT)
    với mọi block * BLOCK_SIZE <= i <= idx + 1: nếu a[i] > a[idx]: R-- (for trâu)

    với mọi blockI > block: R -= tổng(cnt[blockI][1] -> cnt[blockI][a[idx] - 1]) (dùng BIT)
    với mọi idx + 1 <= i <= (block + 1) * BLOCK_SIZE - 1: nếu a[i] < a[idx] : R-- (for trâu)

    cnt[idx / BLOCK_SIZE][a[idx]]--
    ft[idx / BLOCK_SIZE].update(a[idx], -1)
    a[idx] = newVal
    cnt[idx / BLOCK_SIZE][a[i]]++
    ft[idx / BLOCK_SIZE].update(a[idx], 1)

    với mọi blockI < block: R += tổng(cnt[blockI][a[idx] + 1] -> cnt[blockI][5e4]) (dùng BIT)
    với mọi block * BLOCK_SIZE <= i <= idx - 1: nếu a[i] > a[idx]: R++ (for trâu)

    với mọi blockI > block: R += tổng(cnt[blockI][1] -> cnt[blockI][a[idx] - 1]) (dùng BIT)
    với mọi idx + 1 <= i <= (block + 1) * BLOCK_SIZE - 1: nếu a[i] < a[idx] : R++ (for trâu)

Cải tiến version 2
dùng BIT 2D, hoặc dùng một cây BIT tổng để tính nhanh các blockI (tránh vòng for)
*/

// dùng để đếm cặp nghịch thế ban đầu (R)
struct SegmentTree {
    int st[4 * VAL];

    void update(int id, int l, int r, int idx) {
        if (idx < l || idx > r) return;
        if (l == r) return void(st[id]++);
        int m = l + r >> 1;
        update(id * 2, l, m, idx);
        update(id * 2 + 1, m + 1, r, idx);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }
} it;

// BIT + SqrtDecompose
int ft[BLOCK_SIZE + 5][VAL];

void update(int block, int idx, int val) {
    for (int i = block; i <= MAX_BLOCK; i += i & -i)
        for (int j = idx; j <= 5e4; j += j & -j) ft[i][j] += val;
}

int get(int block, int idx) {
    int res = 0;
    for (int i = block; i > 0; i -= i & -i)
        for (int j = idx; j > 0; j -= j & -j) res += ft[i][j];
    return res;
}

int get(int blockL, int valL, int blockR, int valR) {
    return get(blockR, valR) - get(blockL - 1, valR) - get(blockR, valL - 1) + get(blockL - 1, valL - 1);
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
    // đếm số cặp nghịch thế ban đầu
    long long r = 0;
    
    forDown(i, n, 1, -1) {
        r += it.get(1, 1, 5e4, 1, a[i] - 1);
        it.update(1, 1, 5e4, a[i]);
    }

    forUp(i, 1, n, 1) update((i - 1) / BLOCK_SIZE + 1, a[i], 1);

    cin >> q;
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        int block = (idx - 1) / BLOCK_SIZE + 1;

        r -= get(1, a[idx] + 1, block - 1, 5e4);
        forUp(i, (block - 1) * BLOCK_SIZE + 1, idx - 1, 1) if (a[i] > a[idx]) r--;

        r -= get(block + 1, 1, MAX_BLOCK, a[idx] - 1);
        forUp(i, idx + 1, min(n, block * BLOCK_SIZE), 1) if (a[i] < a[idx]) r--;

        update(block, a[idx], -1);
        a[idx] = val;
        update(block, a[idx], 1);

        r += get(1, a[idx] + 1, block - 1, 5e4);
        forUp(i, (block - 1) * BLOCK_SIZE + 1, idx - 1, 1) if (a[i] > a[idx]) r++;

        r += get(block + 1, 1, MAX_BLOCK, a[idx] - 1);
        forUp(i, idx + 1, min(n, block * BLOCK_SIZE), 1) if (a[i] < a[idx]) r++;

        cout << r << endl;
    }
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/sqrt_f