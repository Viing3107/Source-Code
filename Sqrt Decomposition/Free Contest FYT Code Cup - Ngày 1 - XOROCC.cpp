#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int N = 1e5 + 5;
const int MAX_ELEMENT = (1ll << 17) + 7;
const short MAX = 320;

int n, q, a[N], cnt[MAX][MAX_ELEMENT], lazy[MAX], L[MAX], R[MAX];
short block[N], BLOCK_SIZE;

void lazyPropagation(int l, int r) {
    for (int i = L[block[l]]; i <= R[block[l]]; i++) {
        cnt[block[l]][a[i]]--;
        a[i] ^= lazy[block[l]];
        cnt[block[l]][a[i]]++;
    }
    lazy[block[l]] = 0;
}

void manualUpdate(int l, int r, int val) {
    for (int i = l; i <= r; i++) {
        cnt[block[l]][a[i]]--;
        a[i] ^= val;
        cnt[block[l]][a[i]]++;
    }
}

void update(int l, int r, int val) {
    if (block[l] == block[r]) {
        manualUpdate(l, r, val);
        return;
    }
    for (int id = block[l] + 1; id <= block[r] - 1; id++) lazy[id] ^= val;
    manualUpdate(l, R[block[l]], val);
    manualUpdate(L[block[r]], r, val);
}

int manualGet(int l, int r, int val) {
    lazyPropagation(l, r);
    return count(a + l, a + r + 1, val);
}

int get(int l, int r, int val) {
    if (block[l] == block[r]) return manualGet(l, r, val);
    int res = 0;
    for (int id = block[l] + 1; id <= block[r] - 1; id++) res += cnt[id][val ^ lazy[id]];
    res += manualGet(l, R[block[l]], val) + manualGet(L[block[r]], r, val);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    cin >> n >> q;
    BLOCK_SIZE = sqrt(n) + 1;
    block[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % BLOCK_SIZE == 0) {
            block[i] = block[i - 1] + 1;
            L[block[i]] = i;
        }
        else block[i] = block[i - 1];
        R[block[i]] = i;
        cnt[block[i]][a[i]]++;
    }
    while (q--) {
        int type, l, r, val;
        cin >> type >> l >> r >> val;
        if (type == 1) update(l, r, val);
        else cout << get(l, r, val) << "\n";
    }
}

// https://oj.vnoi.info/problem/fc_fyt_day1_xorocc
