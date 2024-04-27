#include <bits/stdc++.h>
# define ll long long

using namespace std;

int d[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int n;

// D(n) : chu so tan cung khac 0 cua n!
// neu chu so hang chuc cua n la le : D(n) = 4 * D(n / 5) * D(n / 10) % 10 
// neu chu so hang chuc cua n la chan : D(n) = 6 * D(n / 5) * D(n / 10) % 10 

int calc(int n){
	if (n < 10) return d[n];
	else if (n / 10 % 10 % 2) return 4 * calc(n / 5) * calc(n % 10) % 10;
	else return 6 * calc(n / 5) * calc(n % 10) % 10;
}

int main(){
	
    cin >> n;
    cout << calc(n);
	
    return 0;
}

// https://oj.vnoi.info/problem/tcdfz
