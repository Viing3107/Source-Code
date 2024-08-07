#include <bits/stdc++.h>

using namespace std;

/*

ban đầu có 1 đường tròn, số miền là 2
có 2 đường tròn, đường tròn này cắt đường tròn ban đầu tại 2 điểm, số miền tăng thêm 2
có 3 đường tròn, đường tròn này cắt 2 đường tròn trước đó tại 4 điểm, số miền tăng thêm 4
có 4 đường tròn, đường tròn này cắt 3 đường tròn trước đó tại 6 điểm, số miền tăng thêm 6
có 5 đường tròn, đường tròn này cắt 4 đường tròn trước đó tại 8 điểm, số miền tăng thêm 8
...
có n đường tròn, đường tròn này cắt n - 1 đường tròn trước đó tại 2 * (n - 1) điểm, số miền tăng thêm 2 * (n - 1)

-> đáp án : 2 + (2 + 4 + 6 + 8 + ... + 2 * (n - 1))
= 2 + 2 * [1 + 2 + 3 + ... + (n - 1)]
= 2 + (n - 1) * n

*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    if (!n) cout << 1;
    else cout << n * (n - 1) + 2;
}

// https://oj.vnoi.info/problem/fc009_circles