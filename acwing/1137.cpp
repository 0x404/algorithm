#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1050, M = 22550;

struct Node{
    int x, d;

    bool operator < (const Node& rhs) const{
        return d > rhs.d;
    }

    Node(int _x, int _d) : x(_x), d(_d) {}

};


int h[N], to[M], nex[M], w[M], cnt;
int dis[N], vis[N], n, m, s;

void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

int dij(int E){
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<Node> heap;
    dis[0] = 0;
    heap.push(Node(0, 0));
    while(!heap.empty()){
        auto now = heap.top(); heap.pop();
        if(vis[now.x]) continue;
        vis[now.x] = 1;
        if(now.x == E) return now.d;

        for(int e = h[now.x]; e; e = nex[e]){
            int v = to[e];
            if(dis[v] > dis[now.x] + w[e]){
                dis[v] = dis[now.x] + w[e];
                heap.push(Node(v, dis[v]));
            }
        }
    }
    return -1;
}

int main(){
    while(cin >> n >> m >> s){
        memset(h, 0, sizeof h);
        cnt = 0;
        for(int i = 1; i <= m; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        int k; cin >> k;
        while(k--){
            int x; scanf("%d", &x);
            add(0, x, 0);
        }
        cout << dij(s) << endl;
    }
    return 0;
}