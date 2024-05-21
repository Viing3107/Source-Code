/*
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 17:43:10 - 21/05/2024

*/
#include                        <bits/stdc++.h>
#define int                     long long
#define task                    "test"
#define forUp(i, l, r, step)    for(int i = l; i <= r; i += step)
#define forDown(i, l, r, step)  for(int i = l; i >= r; i += step)

using namespace std;

const int N     = 1e5 + 5;
const int MOD   = 1e9 + 7;
const int INF   = 0x3f3f3f3f3f3f3f3f;
const int LOG   = __lg(N) + 1;

int n, m, par[N][LOG], dist[N], u, v;
// par[i][j] : tổ tiên thứ 2 ^ j của đỉnh i
// dist[i] : khoảng cách từ đỉnh i đến đỉnh gốc (hay còn gọi là độ sâu của đỉnh i)
vector<int> adj[N];

/*
    Thuật toán tìm LCA của u và v có thể chia thành 2 bước sau :
        (*) Bước 1 : Cân bằng độ sâu
            - Giả định đỉnh u có độ sâu lớn hơn đỉnh v
            - Đỉnh u cần phải nhảy lên cha của chính nó cho đến khi : 
                + độ sâu của đỉnh u = độ sâu của đỉnh v
        (*) Bước 2 : 
            - Đỉnh u và đỉnh v cùng nhảy lên cha của chính nó cho đến khi :
                + cha của đỉnh u = cha của đỉnh v
        --> Time Complexity : O(n)

    Thuật toán trên có thể tối ưu hơn khi sử dụng kỹ thuật "Binary Lifting" :
        - Cụ thể, ở mỗi lần nhảy, có thể nhảy một số bước bằng một lũy thừa của 2
        - Để có thể nhảy mỗi lần một số bước là lũy thừa của 2, ta dùng ý tưởng sau đây : 
            + Xét các lũy thừa của 2 từ lớn về bé, nếu nhảy từ vị trí hiện tại 2 ^ i bước mà không "đi quá giới hạn" thì nhảy luôn
    Chi tiết cách cài đặt như sau :
        (*) Bước 1 : Cân bằng độ sâu
            - Giả định đỉnh u có độ sâu lớn hơn đỉnh v
            - Xét các lũy thừa của 2 từ lớn về bé, nếu đỉnh u nhảy lên đỉnh cha của nó 2 ^ i bước mà độ sâu của đỉnh u không nhỏ hơn độ sâu của đỉnh v thì nhảy luôn
        (*) Bước 2 : Khác với thuật O(n), bước 2 của thuật này chia làm 2 giai đoạn
            - Hai đỉnh cùng nhảy đến vị trí xa nhất (xa 2 đỉnh nhất) mà chưa gặp nhau :
                + Xét các lũy thừa của 2 từ lớn về bé, nếu thấy cả u và v đều nhảy 2 ^ i bước mà chưa gặp nhau thì nhảy luôn
            - Từ vị trí này, hai đỉnh cùng nhảy 1 bước cuối cùng, đây chính là LCA(u, v)
        --> Time Complexity : O(log(n))
*/

void DFS(int u){
    for (auto v : adj[u]){
        /*
            Xét các đỉnh u kề với đỉnh v, khi đó u và v sẽ có các quan hệ sau :
                - v là cha của u (par[u][0] = v)
                - u là cha của v (par[v][0] = u)
                --> nếu v không phải cha của u thì u là cha của v
        
        */
        if (par[u][0] != v){
            dist[v] = dist[u] + 1;
            /*
                Tính toán mảng par :
                    - Cha của v chính là tổ tiên thứ nhất (tổ tiên thứ 2 ^ 0) của v : 
                        par[v][0] = u
                    - Gọi x là tổ tiên thứ 2 ^ (j - 1) của v, khi đó :
                        + Tổ tiên thứ 2 ^ j của v sẽ là tổ tiên thứ 2 ^ (j - 1) của x. Hay nói cách khác, tổ tiên thứ 2 ^ j của v sẽ là tổ tiên thứ 2 ^ (j - 1) của (tổ tiên thứ 2 ^ (j - 1) của v)
                            par[v][j] = par[par[v][j - 1]][j - 1]
            
            */
            par[v][0] = u;
            forUp(j, 1, LOG, 1) par[v][j] = par[par[v][j - 1]][j - 1];
            DFS(v);
        }
    }
}

int LCA(int u, int v){
    if (dist[u] < dist[v]) swap(u, v);
    // (*) Bước 1 : Cân bằng độ sâu
    forDown(i, LOG, 0, -1) if (dist[par[u][i]] >= dist[v]) u = par[u][i];
    if (u == v) return u;
    // (*) Bước 2 : Cùng nhảy
    forDown(i, LOG, 0, -1) if (par[u][i] != par[v][i]){
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    cin >> n >> m;
    forUp(i, 1, m, 1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    dist[0] = -1; // Vì dist[1] = 0 nên ta gán dist[0] = -1 để tránh nhảy nhầm vào đỉnh 0
    cout << LCA(1, 7);

    return (0 ^ 0);
}

/*

    /\_/\
   (= ._.)
   />0   \>1 VOI

*/

// 
