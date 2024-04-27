# include <bits/stdc++.h>
# define int unsigned long long
# define task "file"
# define forEach(it, v) for(typeof((v).begin()) it = (v).begin(), _e = (v).end(); it != _e; it++)
# define forUp(variable, start, end, step) for(int variable = start; variable <= end; variable += step)
# define forDown(variable, start, end, step) for(int variable = start; variable >= end; variable += step)

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
int n;

int binaryExponentiation(int a, int b, int MOD){
	int res = 1;
	while(b){
		if (b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

bool RabinMiller(int n, int iteration){
    if(n < 3) return n == 2;
    if(!n % 2) return false;
    int s = n - 1, p = 0;
    while(!s % 2) s /= 2, p++;
    while(iteration--){
        int x = binaryExponentiation(rand() % (n - 1) + 1, s, n);
        forUp(i, 1, p, 1){
            int xx = x;
            x = x * x % n;
            if (x && xx != 1 && xx != n - 1) return false;
        }
        if (x != 1) return false;
    }
    return true;
}

void input(){
	if (fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	cin >> n;
}

void init(){
}

void solve(){
	if(RabinMiller(n, 10)) cout << "YES\n";
	else cout << "NO\n";
}

void output(){
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	init();
	solve();
	output();

	return 0;
}

/*   /\_/\
    (= ._.)
    / >0  \>1 VOI
*/

// 