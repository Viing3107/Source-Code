# include <bits/stdc++.h>
# define int long long
# define task "test"

using namespace std;

const int MOD = 0x3f3f3f3f3f3f3f3f;
const int LIM = 1e18;
int n, cnt;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

	cin >> n;
	while (n % 2 == 0){
        cnt++;
        n /= 2;
    }
    if (cnt > 1){
        cout << "YES";
        return 0;
    }
    cnt = 0;
    while (n % 3 == 0){
        cnt++;
        n /= 3;
    }
    if (cnt > 1){
        cout << "YES";
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6){
        cnt = 0;
        while (n % i == 0){
            cnt++;
            n /= i;
        }
        if (cnt > 1){
            cout << "YES";
            return 0;
        }
        cnt = 0;
        while (n % (i + 2) == 0){
            cnt++;
            n /= (i + 2);
        }
        if (cnt > 1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
	
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// https://oj.vnoi.info/problem/fcb031_sqfree