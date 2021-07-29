#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

const int N = 1050, M = 40500, K = 150;


struct Node{
    int p, k, d;

    bool operator < (const Node & rhs) const{
        return d > rhs.d;
    }

    Node(int _p, int _k, int _d) : p(_p), k(_k), d(_d) {}

};

int h[M], to[M], nex[M], w[M], cnt;
int dis[N][K], cost[N], n, m, q;
bool vis[N][K];


void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

int dij(int limit, int S, int E){
    priority_queue<Node> q;
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[S][0] = 0;
    q.push(Node(S, 0, 0));
    while(!q.empty()){
        auto now = q.top(); q.pop();
        if(vis[now.p][now.k]) continue;
        vis[now.p][now.k] = true;
        if(now.p == E) return now.d;
        if(now.k + 1 <= limit && dis[now.p][now.k + 1] > dis[now.p][now.k] + cost[now.p]){
            dis[now.p][now.k + 1] = dis[now.p][now.k] + cost[now.p];
            q.push(Node(now.p, now.k + 1, dis[now.p][now.k + 1]));
        }

        for(int e = h[now.p]; e; e = nex[e]){
            int v = to[e];
            if(w[e] <= limit && now.k >= w[e] && dis[v][now.k - w[e]] > dis[now.p][now.k]){
                dis[v][now.k - w[e]] = dis[now.p][now.k];
                q.push(Node(v, now.k - w[e], dis[v][now.k - w[e]]));
            }
        }
    }   

    int ans = INF;
    for(int i = 0; i <= limit; i++) ans = min(ans, dis[E][i]);

    return ans == INF ? -1 : ans;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 1, a, b, c; i <= m; i++){
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    cin >> q;
   
    while(q--){
        int c, s, e;
        cin >> c >> s >> e;
        int ans = dij(c, s, e);
        
        if(ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;

    }
    cin.get();
    cin.get();
    return 0;
}