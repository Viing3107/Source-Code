/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:35:04 - 09/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e3 + 3;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

int n, s, result;

struct cup{
    int t, v, id, val;
} a[N];

bool cmp(cup u, cup v){
    return u.v > v.v;
}

bool cmp2(cup u, cup v){
    return u.id < v.id;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    forUp(i, 1, n, 1){
        cin >> a[i].t >> a[i].v;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    forUp(i, 1, n, 1) s += a[i].t;
    forUp(i, 1, n, 1){
        if (s >= a[i].v){
            a[i].val = a[i].v;
            s -= a[i].v;
        }
        else{
            a[i].val = s;
            break;
        }
    }
    sort(a + 1, a + n + 1, cmp2);
    forUp(i, 1, n, 1) result += (a[i].val == 0);
    cout << result << endl;
    forUp(i, 1, n, 1) cout << a[i].val << " ";
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// https://oj.vnoi.info/problem/coci1920_r4_psk