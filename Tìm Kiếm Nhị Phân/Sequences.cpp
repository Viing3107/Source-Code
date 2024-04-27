# include <bits/stdc++.h>
# define ll long long
# define endl "\n"

using namespace std;

const ll N = 1e5 + 5;
int n, LDS[N], LIS[N], a[N], x[N];

void lis() {
    fill(x + 1, x + n + 1, 1e9);
    x[0] = -1e9; 
	int len = 0;
    for(int i = 0; i < n; i++) {
        int p = lower_bound(x, x + len + 1, a[i]) - x;
        LIS[i] = p;
        len = max(len, p);
        x[p] = min(x[p], a[i]);
    }
}

void lds() {
    fill(x + 1, x + n + 1, 1e9);
    x[0] = -1e9; 
	int len = 0;
    for(int i = n - 1; i >= 0; i--) {
        int p = lower_bound(x, x + len + 1, a[i]) - x;
        LDS[i] = p;
        len = max(len, p);
        x[p] = min(x[p], a[i]);
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	lis();
	lds();
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res, 2 * min(LIS[i], LDS[i]) - 1);
	cout << res << endl;
	
	return 0;
}
