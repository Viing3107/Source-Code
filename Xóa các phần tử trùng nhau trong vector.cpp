#include <bits./stdc++.h>
#define task "test"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    vector<int> v = {1, 1, 4, 1, 3, 4, 2, 4, 3, 5, 2, 4, 2, 4, 1, 1};
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto &x : v) cout << x << endl;
}
