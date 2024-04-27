# include <bits/stdc++.h>
# define ll long long

using namespace std;

string s;
map<char, int> mp;
char temp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) mp[s[i]]++;
	ll ans =  0;
	while (mp.size() > 2){
		int res = 1e5;
		for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++){
			if (res > (*it).second){
				res = min(res, (*it).second);
				temp = (*it).first;
			}
		}
		ans += res;
		mp.erase(temp);
	}
	cout << ans << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/fc027_simplicity
