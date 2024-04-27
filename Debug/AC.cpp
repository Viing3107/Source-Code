#include        <bits/stdc++.h>
#define pb      push_back
#define fi      first
#define se      second
#define int     long long 
#define pii     pair<long long, long long>
#define endl    "\n"
#define TIME    (1.0 * clock() / CLOCKS_PER_SEC)
#define rnd(n)  setprecision(n) << fixed
#define FILE(A) if (fopen(A".INP","r")) {freopen(A".INP", "r", stdin); freopen(A".OUT", "w", stdout);}

using namespace std;

const int N    = 1e4+4;
const int oo   = 1e16 ;
const int MOD  = 1e9+7;
const int BASE = 31   ;

int n,res,ans;
pii a[N];

bool cmp(pii s, pii t) {
    if (s.se==t.se) return s.fi <t.fi;
    return s.se < t.se;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    FILE("test")

    cin >> n;
    for (int i=1 ; i<=n ; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1,cmp);

    for (int i=1 ; i<=n ; i++) {

        int s=a[i].fi, t=a[i].se;
        res=t-s;
        // cout << i << " ";
        for (int j=i+1 ; j<=n ; j++) {
            if (a[j].fi >= t) {
                s=a[j].fi;
                t=a[j].se;
                res+=t-s;
                // cout << j << " ";
            }
        }
        // cout << res << endl;

        ans=max(ans,res);
    }
    cout << ans;
    // for (int i=1 ; i<=n ; i++) {
    //     cout << a[i].fi << " " << a[i].se;
    //     cout << endl;
    // }
    return 0;
}
//-.-. --- -.. . / -... -.-- / -. .. -. ....
