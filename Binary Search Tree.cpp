/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 20:43:43 - 27/06/2024

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

class BinarySearchTree{
    public :
        struct node{
            int data;
            node *left, *right;

            node(int val){
                data = val;
                left = right = nullptr;
            }
        } *head;

        node *insert(node *head, int val){
            if (head == nullptr) return new node(val);
            if ((*head).data < val) (*head).right = insert((*head).right, val);
            else (*head).left = insert((*head).left, val);
            return head;
        }

        node *leftMost(node *head){
            return ((*head).left == nullptr) ? head : leftMost((*head).left);
        }

        node *erase(node *head, int val){
            if (head == nullptr) return nullptr;
            if ((*head).data < val) (*head).right = erase((*head).right, val);
            else if ((*head).data > val) (*head).left = erase((*head).left, val);
            else{
                if ((*head).left == nullptr && (*head).right == nullptr) delete head;
                else if ((*head).left != nullptr && (*head).right == nullptr) return (*head).left;
                else if ((*head).left == nullptr && (*head).right != nullptr) return (*head).right;
                else{
                    node *tmp = leftMost((*head).right);
                    (*head).data = (*tmp).data;
                    (*head).right = erase((*head).right, (*tmp).data);
                    return head;
                }
            }
        }
        void search(node *head, int val){
            if (head == nullptr) return;
            cout << (*head).data << "\n";
            if ((*head).data < val) search((*head).right, val);
            else search((*head).left, val);
        }
} bst;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    bst.head = bst.insert(bst.head, 50);
    bst.head = bst.insert(bst.head, 60);
    bst.head = bst.insert(bst.head, 70);
    forUp(i, 1, 10, 1) bst.head = bst.insert(bst.head, i);
    bst.erase(bst.head, 50);
    bst.search(bst.head, 6);
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " .\n";

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 