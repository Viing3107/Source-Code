// code by viing3107
#pragma GCC optimize("O2", "O3", "Ofast")
#pragma target("avx", "avx2", "fma")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define task "test"
#define forUp(i, l, r, step) for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step) for(int i = l; i >= r; i += step)
#define forEach(it, v) for(typeof v.begin() it = v.begin(), _e = v.end(); it != _e; it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b

using namespace std;

const int N   = 1e5 + 5;

int n, a[N], s, k, cnt;
// cnt : đếm số lượng dãy con có tổng bằng k

map<int, int> mp;
/*

    mp[key] = value : dãy con có tổng bằng key xuất hiện value lần
    mp[key] : key = preSum[i]
    có thể thay map<int, int> mp bằng int mark[N] nêú a[i] nhỏ
    
*/ 

bool check;

void solve1(){
    cin >> n >> k;
    forUp(i, 1, n, 1){
        cin >> a[i];
        s += a[i];
        // dãy con từ a[0] --> a[i] có tổng bằng k
        if (s == k) cnt++;

        /*
        
        nhận xét : 
            (*) xuất hiện dãy con có tổng bằng i (i < s) thì sẽ xuất hiện dãy con có tổng bằng s - i
            (*) số lượng dãy con có tổng bằng i = số lượng dãy con có tổng bằng s - i
        
        */

        // dãy con từ a[j] --> a[i] có tổng bằng k <=> dãy con từ a[0] --> a[j - 1] có tổng bằng s - k
        cnt += mp[s - k];
        mp[s]++;
    }
    cout << cnt;
}

void solve2(){
    cin >> n >> k;
    forUp(i, 1, n, 1) cin >> a[i];
    for(int l = 1, r = 1; r <= n; r++){
        // nếu tổng nhỏ hơn k --> cộng tổng và tăng r
        s += a[r];
        // nếu tổng lớn hơn k --> trừ tổng và tăng l
        while (s > k && l < r) s -= a[l++];
        // nếu tổng bằng k --> tăng biến đếm
        cnt += (s == k);
    }

    cout << cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    solve1();

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// solve1 được dưa trên ý tưởng của hungaya : https://daynhauhoc.com/t/code-dem-so-luong-day-con-co-tong-bang-k-bi-time-limit-exceeded/79292/8
// solve2 được dựa trên ý tưởng hai con trỏ : https://dothanhspyb.com/dem-so-luong-mang-con-co-tong-bang-x/