# include <bits/stdc++.h>

using namespace std;

int res, a[100005], presufSum[100005], n;
bool ok;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		res += a[i];
	} 
	presufSum[1] = a[1] + a[2];
	for (int i = 2; i < n; i++) presufSum[i] = a[i - 1] + a[i] + a[i + 1];
	presufSum[n] = a[n - 1] + a[n];
	ok = false;
	for (int i = 1; i <= n; i++){
		if (presufSum[i] <= -1){
			cout << res + 4 << endl; 
			ok = true;
			break;
		} 
	}
	if (!ok){
		for (int i = 1; i < n; i++){
			if (a[i] != a[i + 1]){
				cout << res << endl;
				ok = true;
				break;
			}
		}
	}
	if (!ok) cout << res - 4 << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fc145_maxflip