#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, q, BLOCK_SIZE, answer[N], cntdiff[30], l, r = -1, cntQuery = -1, cnt;
string s, t;

struct UpdateQuery {
    int idx;
    char oldVal, newVal;
    // tồn tại truy vấn cập nhật a[idx] = oldVal -> a[idx] = newVal
};

struct GetQuery {
    int l, r, cnt, id;

    friend bool operator < (const GetQuery &u, const GetQuery &v) {
        if (u.l / BLOCK_SIZE != v.l / BLOCK_SIZE) return u.l < v.l;
        if (u.r / BLOCK_SIZE != v.r / BLOCK_SIZE) {
            if (u.l / BLOCK_SIZE & 1) return u.r < v.r;
            return u.r > v.r;
        }
        return u.cnt < v.cnt;
    }
};

vector<UpdateQuery> updates;
vector<GetQuery> queries;

void update(int idx, char c) {
    if (idx >= l && idx <= r) {
        cntdiff[s[idx] - 'a' + 1]--;
        cnt -= !cntdiff[s[idx] - 'a' + 1];
        cnt += !cntdiff[c - 'a' + 1];
        cntdiff[c - 'a' + 1]++;
    }
    s[idx] = c;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> s;
    s = " " + s;
    t = s;
    BLOCK_SIZE = pow(n, 2.0 / 3.0) + 1; // nên tạo BLOCK_SIZE riêng cho mỗi input
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type, idx, l, r;
        char c;
        cin >> type;
        if (type == 1) {
            cin >> idx >> c;
            updates.push_back({idx, t[idx], c});
            t[idx] = c;
        }
        else {
            cin >> l >> r;
            queries.push_back({l, r, (int) updates.size() - 1, i});
        }
    }
    sort(queries.begin(), queries.end());
    // for (auto &q : queries) cout << q.l << " " << q.r << " " << q.cnt << endl;
    for (auto &q : queries) {
        // truy vấn cập nhật
        while (cntQuery < q.cnt) {
            cntQuery++;
            update(updates[cntQuery].idx, updates[cntQuery].newVal);
        }
        // đảo ngược truy vấn cập nhật
        while (cntQuery > q.cnt) {
            update(updates[cntQuery].idx, updates[cntQuery].oldVal);
            cntQuery--;
        }
        // Mo's Algorithm
        while (l < q.l) {
            cntdiff[s[l] - 'a' + 1]--;
            cnt -= !cntdiff[s[l] - 'a' + 1];
            l++;
        }
        while (l > q.l) {
            l--;
            cnt += !cntdiff[s[l] - 'a' + 1];
            cntdiff[s[l] - 'a' + 1]++;
        }
        while (r < q.r) {
            r++;
            cnt += !cntdiff[s[r] - 'a' + 1];
            cntdiff[s[r] - 'a' + 1]++;
        }
        while (r > q.r) {
            cntdiff[s[r] - 'a' + 1]--;
            cnt -= !cntdiff[s[r] - 'a' + 1];
            r--;
        }

        answer[q.id] = cnt;
    }
    // in ra các truy vấn get theo thứ tự input
    sort(queries.begin(), queries.end(), [&] (const GetQuery &u, const GetQuery &v) -> bool {
        return u.id < v.id;
    });
    for (auto &q : queries) cout << answer[q.id] << "\n";
}

// https://oj.vnoi.info/problem/fc133_charcnt