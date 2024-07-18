/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 13:07:38 - 18/07/2024

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

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

/*
    Đề bài : cho một cây n đỉnh, mỗi đỉnh có một giá trị a[i]. có q truy vẫn thuộc 2 loại sau :
        1 u val : gán a[u] = val
        2 u v : tính tổng giá trị trong đường đi a -> b

*/

int n, a[N], q;
vector<int> adj[N];
int par[N]; // par[u] : cha trực tiếp của u
int sz[N]; // sz[u] : kích thước của cây con gốc u
int depth[N]; // depth[u] : độ sâu của đỉnh u
int arr[N];
/*
    arr[] : mảng lưu lại thứ tự đi thăm đỉnh u
    LƯU Ý : ưu tiên đi thăm bigChild trước để tạo ra chuỗi nặng, sau đó mới đi thăm các đỉnh còn lại
*/
int pos[N]; // pos[u] : vị trí của u trong mảng arr[]
int chainId[N]; // chainId[u] : chuỗi mà u nằm trong
int chainHead[N]; // chainHead[i] : node đầu tiên trong chuỗi i
int curChain = 1; // biến lưu lại chỉ số của chuỗi trong mảng arr[]
int curPos; // biến lưu lại vị trí của chuỗi trong mảng arr[]

void DFS(int u, int p = 0) {
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) {
        depth[v] = depth[u] + 1;
        par[v] = u;
        DFS(v, u);
        sz[u] += sz[v];
    }
}

void HLD(int u, int p = 0) {
    if (!chainHead[curChain]) chainHead[curChain] = u;
    chainId[u] = curChain;
    pos[u] = ++curPos;
    arr[curPos] = u;
    // tìm bigChild
    int bigChild = 0;
    for (auto &v : adj[u]) if (v != p) {
        if (sz[v] > sz[bigChild]) bigChild = v;
    }
    // đi thăm bigChild
    if (bigChild) HLD(bigChild, u);
    // đi thăm các đỉnh còn lại
    for (auto &v : adj[u]) if (v != p && v != bigChild) {
        curChain++;
        HLD(v, u);
    }
}

int LCA(int u, int v) {
    // mặc định chainId[u] < chainId[v]. khi đó v sẽ phải nhảy 
    if (chainId[u] > chainId[v]) swap(u, v);
    // nhảy lên chuỗi có số thứ tự (chainId[]) bé hơn cho đến khi u và v cùng chuỗi. khi đó đỉnh nào có độ sâu thấp hơn sẽ là LCA
    while (chainId[u] != chainId[v]) v = par[chainHead[chainId[v]]];
    return ((depth[u] < depth[v]) ? u : v);
}

struct SegmentTree{
    int st[4 * N];

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[arr[l]];
            return;
        }
        int m = l + r >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void update(int id, int l, int r, int idx, int val) {
        if (idx < l || idx > r) return;
        if (l == r) {
            st[id] = val;
            return;
        }
        int m = l + r >> 1;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    int get(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return 0;
        if (u <= l && r <= v) return st[id];
        int m = l + r >> 1;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }

    int query(int u, int v) {
        int lca = LCA(u, v), result = 0;
        for (; chainId[u] > chainId[lca]; u = par[chainHead[chainId[u]]]) result += get(1, 1, n, pos[chainHead[chainId[u]]], pos[u]);
        for (; chainId[v] > chainId[lca]; v = par[chainHead[chainId[v]]]) result += get(1, 1, n, pos[chainHead[chainId[v]]], pos[v]);
        result += ((depth[u] < depth[v]) ? get(1, 1, n, pos[u], pos[v]) : get(1, 1, n, pos[v], pos[u]));
        return result;
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> q;
    forUp(i, 1, n, 1) cin >> a[i];
    forUp(i, 1, n - 1, 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    HLD(1);
    it.build(1, 1, n);
    while (q--) {
        int type, u, v, val;
        cin >> type;
        if (type == 1) {
            cin >> u >> val;
            it.update(1, 1, n, pos[u], val);
        }
        else {
            cin >> u >> v;
            cout << it.query(u, v) << endl;
        }
    }
    // forUp(i, 1, curPos, 1) cout << arr[i] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << pos[i] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << chainId[i] << " ";
    // cout << endl;
    // forUp(i, 1, curChain, 1) cout << chainHead[i] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << chainHead[chainId[i]] << " ";
    // cout << endl;
    // forUp(i, 1, n, 1) cout << a[arr[i]] << " ";
    // cout << endl;

    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 