#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;

const int N = 1e5 + 50, M = 4e5 +50, MOD = 100003;

int h[N], to[M], nex[M], cnt;
int dis[N], ans[N], vis[N], n, m;

struct Node{
    int x, d;

    bool operator < (const Node& rhs) const{
        return d > rhs.d;
    }

    Node(int _x, int _d) : x(_x), d(_d) {}

};

void add(int u, int v){
    to[++cnt] = v; nex[cnt] = h[u]; h[u] = cnt;
}

void dij(){
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<Node> heap;
    heap.push(Node(1, 0));
    dis[1] = 0;
    ans[1] = 1;
    while(!heap.empty()){
        auto now = heap.top(); heap.pop();
        if(vis[now.x]) continue;
        vis[now.x] = true;
        for(int e = h[now.x]; e; e = nex[e]){
            int v = to[e];
            if(now.d + 1 < dis[v]){
                dis[v] = now.d + 1;
                ans[v] = ans[now.x];
                heap.push(Node(v, dis[v]));
            }
            else if(now.d + 1 == dis[v]){
                ans[v] = (ans[v] + ans[now.x]) % MOD;
                heap.push(Node(v, dis[v]));
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}   

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dij();
    // cin.get();
    // cin.get();
    return 0;

}