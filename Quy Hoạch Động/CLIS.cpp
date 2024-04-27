# include <bits/stdc++.h>

using namespace std;

string s;
int a[222];

void LIS(){
	vector<int> res;
	res.push_back(a[1]);
	int len = 1;
	for (int i = 2; i <= s.size(); i++){
		if (res[len - 1] <= a[i]){
			res.push_back(a[i]);
			len++;
		} 
		else{
			int index = upper_bound(res.begin(), res.end(), a[i]) - res.begin();
			res[index] = a[i];
		}
	}
	cout << len << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	for (int i = 1; i <= s.size(); i++) a[i] = s[i - 1];
	LIS();
	
	return 0;
}

// https://oj.vnoi.info/problem/fc014_clis
