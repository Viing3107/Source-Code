/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:27:24 - 23/07/2024

*/

#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define endl                    "\n"
#define task                    "test"
#define all(v)                  (v).begin(), (v).end()
#define forUp(i, l, r, step)    for (int i = (l); i <= (r); i += step)
#define forDown(i, l, r, step)  for (int i = (l); i >= (r); i += step)
#define forEach(it, v)          for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N             = 1e5 + 5;
const int MOD           = 1e9 + 7;
const int INF           = 0x3f3f3f3f3f3f3f3f;

int q;

struct DynamicMedian{
    /*
        diff = (số giá trị không bị xóa ở hàng đợi l) - (số giá trị không bị xóa ở hàng đợi r)
    */
    int diff = 0;
    
    /*
        Queue
        Chứa các giá trị không bị xóa và giá trị chắc chắn bị xóa nhưng chưa cần xóa ngay
    */
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    /*
        Erasing Queue
        Chỉ chứa các giá trị chắc chắn bị xóa nhưng chưa cần xóa ngay
        Chỉ xóa khi 
            l.top() == leq.top() : -> l.pop(), leq.pop()
            r.top() == req.top() : -> r.pop(), req.pop()
    */
    priority_queue<int> leq;
    priority_queue<int, vector<int>, greater<int>> req;

    void balance() {
        if (diff < 0) {
            assert(!r.empty());
            l.push(r.top());
            r.pop();
            diff += 2;
        }
        else if (diff > 1) {
            assert(!l.empty());
            r.push(l.top());
            l.pop();
            diff -= 2;
        }
        while (!leq.empty() && l.top() == leq.top()) {
            l.pop();
            leq.pop();
        }
        while (!req.empty() && r.top() == req.top()) {
            r.pop();
            req.pop();
        }
    }

    int median() {
        balance();
        assert(!l.empty());
        return l.top();
    }

    int median2() {
        balance();
        assert(!r.empty());
        return r.top();
    }

    void insert(const int &val) {
        balance();
        if (l.empty() || val <= median()) {
            l.push(val);
            diff++;
        }
        else {
            r.push(val);
            diff--;
        }
    }

    void erase(const int &val) {
        balance();
        if (val <= median()) {
            (val == median()) ? l.pop() : leq.push(val);
            diff--;
        }
        else {
            (val == median2()) ? r.pop() : req.push(val);
            diff++;
        }
    }
} dm;

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
        char type;
        int val;
        cin >> type >> val;
        if (type == '+') dm.insert(val);
        else dm.erase(val);
        cout << dm.median() << endl;
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 