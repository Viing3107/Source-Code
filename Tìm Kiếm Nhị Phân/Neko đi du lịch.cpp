/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:35:00 - 23/07/2024

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

int n, m;

struct tour{
    int l, r, id;

    friend bool operator < (tour u, tour v) {
        return (u.l == v.l ? u.r < v.r : u.l < v.l);
    }
} a[N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m;
    forUp(i, 1, n, 1) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    forUp(i, 1, n - 1, 1) {
        int l = i + 1, r = n;
        while (r - l >= 0) {
            int mid = l + r >> 1;
            if (a[i].r >= a[mid].l) l = mid + 1;
            else {
                cout << "YES\n" << a[i].id << " " << a[mid].id;
                return (0 ^ 0);
            }
        }
    }
    cout << "NO";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/vnoicup22_r2_a