/*
    Author : Do Quang Vinh
    Vietnam National University - Ha Noi
    Created : 15:47:25 - 18/11/2025

*/

#include                        <bits/stdc++.h>
#define endl                    "\n"
#define task                    "test"
#define int                     long long
#define double                  long double
#define gcd(x, y)               __gcd(x, y)
#define MASK(i)                 (1ll << (i))
#define BIT(i, n)               ((n) >> (i) & 1)
#define SZ(v)                   (int) (v).size()
#define lcm(x, y)               x / gcd(x, y) * y
#define ALL(v)                  (v).begin(), (v).end()
#define LOG(x)                  (63 - __builtin_clzll(x))
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof (v).begin() it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int       LEVEL       = 20;
const int       BASE        = 311;
const int       BLOCK_SIZE  = 320;
const double    EPS         = 1e-6;
const int       N           = 1e5 + 5;
const int       VAL         = 1e6 + 6;
const int       MOD         = 1e9 + 7;
const int       INF         = 0x3f3f3f3f3f3f3f3f;

struct Cell;
struct Column;
struct SkipList;

struct Cell {
    Column *prev, *next;
    int cnt; // số phần tử bị skip qua khi đi từ prev -> next tại level này
};

struct Column {
    int val;
    vector<Cell> cells;
};

struct SkipList {
    Column *head, *tail;
    int sz; // số phần tử trong Skip List

    SkipList() {
        sz = 0;
        head = new Column;
        tail = new Column;
        head->val = -INF;
        tail->val = INF;
        forUp (i, 0, LEVEL - 1, 1) {
            head->cells.push_back({nullptr, tail, 1});
            tail->cells.push_back({head, nullptr, 0});
        }
    }

    bool empty() {return head->cells[0].next == tail;}

    Column *lower_bound(int x) {
        Column *prevCol = head;
        forDown (level, LEVEL - 1, 0, -1) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val < x)
                prevCol = prevCol->cells[level].next;
        }
        return prevCol->cells[0].next;
    }

    Column *upper_bound(int x) {
        Column *prevCol = head;
        forDown (level, LEVEL - 1, 0, -1) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val <= x)
                prevCol = prevCol->cells[level].next;
        }
        return prevCol->cells[0].next;
    }

    void insert(int x) {
        // prev[level]: column đứng ngay trước nơi insertedCol sẽ chèn vào
        Column *prev[LEVEL];
        // prefix[level]: số phần tử đã nhảy qua từ đầu đến vị trí này
        int prefix[LEVEL];
        
        Column *cur = head;
        int cnt = 0;
        forDown (level, LEVEL - 1, 0, -1) {
            while (cur->cells[level].next != tail && cur->cells[level].next->val < x) {
                cnt += cur->cells[level].cnt;
                cur = cur->cells[level].next;
            }
            prev[level] = cur;
            prefix[level] = cnt;
        }

        Column *tmp = lower_bound(x);
        if (tmp != tail && tmp->val == x) return;

        Column *insertedCol = new Column;
        insertedCol->val = x;
        insertedCol->cells.push_back({nullptr, nullptr, 0});
        while (SZ(insertedCol->cells) < LEVEL && rand() % 2 == 0) insertedCol->cells.push_back({nullptr, nullptr, 0});

        forDown (level, LEVEL - 1, 0, -1) {
            if (level < SZ(insertedCol->cells)) {
                Column *prevCol = prev[level];
                Column *nextCol = prevCol->cells[level].next;
                int oldCnt = prevCol->cells[level].cnt;
    
                insertedCol->cells[level].next = nextCol;
                nextCol->cells[level].prev = insertedCol;
                prevCol->cells[level].next = insertedCol;
                insertedCol->cells[level].prev = prevCol;
    
                prevCol->cells[level].cnt = (prefix[0] - prefix[level]) + 1;
                insertedCol->cells[level].cnt = oldCnt - (prefix[0] - prefix[level]);
            }
            else prev[level]->cells[level].cnt++;
        }
        sz++;
    }

    void erase(int x) {
        Column *erasedCol = lower_bound(x);
        if (erasedCol == tail || erasedCol->val != x) return;

        Column *prevCol = head;
        forDown (level, LEVEL - 1, 0, -1) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val < x)
                prevCol = prevCol->cells[level].next;
            if (level < SZ(erasedCol->cells)) {
                Column *nextCol = erasedCol->cells[level].next;

                prevCol->cells[level].cnt += erasedCol->cells[level].cnt - 1;
                prevCol->cells[level].next = nextCol;
                nextCol->cells[level].prev = prevCol;
            }
            else prevCol->cells[level].cnt--;
        }
        delete erasedCol;
        sz--;
    }

    int kth(int k) {
        if (k > sz) return INF;

        Column *prevCol = head;
        int cnt = 0;
        forDown (level, LEVEL - 1, 0, -1) {
            while (prevCol->cells[level].next != tail && cnt + prevCol->cells[level].cnt < k) {
                cnt += prevCol->cells[level].cnt;
                prevCol = prevCol->cells[level].next;
            }
        }
        return prevCol->cells[0].next->val;
    }

    int count(int x) {
        Column *curCol = head;
        int res = 0;
        forDown (level, LEVEL - 1, 0, -1) {
            while (curCol->cells[level].next != tail && curCol->cells[level].next->val < x) {
                res += curCol->cells[level].cnt;
                curCol = curCol->cells[level].next;
            }
        }
        return res;
    }
} sl;

int q, x;
char type;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> q;
    while (q--) {
        cin >> type >> x;
        if (type == 'I') sl.insert(x);
        else if (type == 'D') sl.erase(x);
        else if (type == 'K') {
            int k = sl.kth(x);
            if (k == INF) cout << "invalid\n";
            else cout << k << endl;
        }
        else cout << sl.count(x) << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1

*/

// https://oj.vnoi.info/problem/orderset