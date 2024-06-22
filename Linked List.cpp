/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 21:56:04 - 21/06/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define double                  long double
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)
#define forEach(it, v)          for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;

struct node{
    int data;
    node *next;

    node *makeNode(int x){
        node *res = new node();
        (*res).data = x;
        (*res).next = nullptr;
        return res;
    }

    bool empty(node *head){
        return head = nullptr;
    }

    int size(node *head){
        int cnt = 0;
        for (; head != nullptr; head = (*head).next) cnt++;
        return cnt;
    }

    void push(node *&head, int x, int idx){
        node *tmp = head, *res = makeNode(x);
        if (idx <= 0 || idx > size(head) + 1) return;
        for (int cnt = 1; cnt < idx - 1; cnt++, tmp = (*tmp).next);
        if (idx == 1){
            (*res).next = head;
            head = res;
        }
        else{
            (*res).next = (*tmp).next;
            (*tmp).next = res;    
        }
    }

    void erase(node *&head, int idx){
        if (idx <= 0 || idx > size(head)) return;
        node *tmp = head;
        for (int cnt = 1; cnt < idx - 1; cnt++, tmp = (*tmp).next);
        if (idx == 1) head = (*head).next;
        else (*tmp).next = (*(*tmp).next).next;
    }
} *head;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    (*head).makeNode(100);
    
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 