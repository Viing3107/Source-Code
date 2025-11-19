#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int LEVEL = 20;

struct Cell;
struct Column;
struct SkipList;

struct Cell {
    Column *prev, *next;
};

struct Column {
    int val;
    vector<Cell> cells;
};

struct SkipList {
    Column *head, *tail;

    SkipList() {
        head = new Column;
        tail = new Column;
        head->val = 0;
        tail->val = 0;
        for (int i = 0; i < LEVEL; i++) {
            head->cells.push_back({nullptr, tail});
            tail->cells.push_back({head, nullptr});
        }
    }

    bool empty() {
        return head->cells[0].next == tail;
    }

    Column *lower_bound(int x) {
        Column *prevCol = head;
        for (int level = LEVEL - 1; level >= 0; level--) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val < x) 
                prevCol = prevCol->cells[level].next;
        }
        return prevCol->cells[0].next;
    }

    Column *upper_bound(int x) {
        Column *prevCol = head;
        for (int level = LEVEL - 1; level >= 0; level--) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val <= x)
                prevCol = prevCol->cells[level].next;
        }
        return prevCol->cells[0].next;
    }

    void insert(int x) {
        Column *temp = lower_bound(x);
        if (temp != tail && temp->val == x) return;

        Column *insertedCol = new Column;
        insertedCol->val = x;
        insertedCol->cells.push_back({nullptr, nullptr});
        while (insertedCol->cells.size() < LEVEL && rand() % 2 == 0) insertedCol->cells.push_back({nullptr, nullptr});

        Column *prevCol = head;
        for (int level = LEVEL - 1; level >= 0; level--) {
            while (prevCol->cells[level].next != tail && prevCol->cells[level].next->val < x)
                prevCol = prevCol->cells[level].next;
            if (level < insertedCol->cells.size()) {
                Column *nextCol = prevCol->cells[level].next;
                insertedCol->cells[level].next = nextCol;
                nextCol->cells[level].prev = insertedCol;
                prevCol->cells[level].next = insertedCol;
                insertedCol->cells[level].prev = prevCol;
            }
        }
    }

    void erase(int x) {
        Column *erasedCol = lower_bound(x);
        if (erasedCol == tail || erasedCol->val != x) return;

        Column *curCol = head;
        for (int level = LEVEL - 1; level >= 0; level--) {
            while (curCol->cells[level].next != tail && curCol->cells[level].next->val <= x) 
                curCol = curCol->cells[level].next;
            if (level < erasedCol->cells.size() && curCol == erasedCol) {
                Column *prevCol = curCol->cells[level].prev;
                Column *nextCol = curCol->cells[level].next;
                prevCol->cells[level].next = nextCol;
                nextCol->cells[level].prev = prevCol;
            }
        }
        delete erasedCol;
    }
} sl;

int type, x;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    while (cin >> type) {
        if (!type) return 0;
        else if (type == 1) {
            cin >> x;
            sl.insert(x);
        }
        else if (type == 2) {
            cin >> x;
            sl.erase(x);
        }
        else if (type == 3) {
            if (sl.empty()) cout << "empty\n";
            else cout << sl.head->cells[0].next->val << endl;
        }
        else if (type == 4) {
            if (sl.empty()) cout << "empty\n";
            else cout << sl.tail->cells[0].prev->val << endl;
        }
        else if (type == 5) {
            if (sl.empty()) cout << "empty\n";
            else {
                cin >> x;
                Column *curCol = sl.upper_bound(x);
                if (curCol == sl.tail) cout << "no\n";
                else cout << curCol->val << endl;
            }
        }
        else if (type == 6) {
            if (sl.empty()) cout << "empty\n";
            else {
                cin >> x;
                Column *curCol = sl.lower_bound(x);
                if (curCol == sl.tail) cout << "no\n";
                else cout << curCol->val << endl;
            }
        }
        else if (type == 7) {
            if (sl.empty()) cout << "empty\n";
            else {
                cin >> x;
                Column *nextCol = sl.lower_bound(x);
                if (nextCol->cells[0].prev == sl.head) cout << "no\n";
                else cout << nextCol->cells[0].prev->val << endl; 
            }
        }
        else {
            if (sl.empty()) cout << "empty\n";
            else {
                cin >> x;
                Column *nextCol = sl.upper_bound(x);
                if (nextCol->cells[0].prev == sl.head) cout << "no\n";
                else cout << nextCol->cells[0].prev->val << endl;
            }
        }
    }
}

// https://oj.vnoi.info/problem/cppset