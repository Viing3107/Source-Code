# include <bits/stdc++.h>
# define ll long long

using namespace std;

priority_queue<int> q;
set<int, greater<int> > se;
char s;
int v, temp;

int main(){
	while (cin >> s){
		if (s == '-'){
			if (!q.empty()){
				v = q.top();
				while (!q.empty() && q.top() == v) q.pop();
			}
		}
		else if (q.size() < 15000){
			cin >> v;
			q.push(v);
		}
		
	}
	if (q.size() == 0){
		cout << 0 ;
		return 0;
	}
	while (!q.empty()){
		v = q.top();
		se.insert(v);
		q.pop();
	}
	cout << se.size() << endl;
	for (set<int>::iterator it = se.begin(); it != se.end(); it++) cout << *it << endl;
	
	return 0;
}

// https://oj.vnoi.info/problem/qbheap
