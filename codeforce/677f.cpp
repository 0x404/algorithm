#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 1050
#define MAXM 1000500
#define INF 0x3f3f3f3f
using namespace std;

int h[MAXN], to[MAXM], nex[MAXM], w[MAXM], cnt;
int passBy[MAXN][MAXN], d[MAXN][MAXN], ls[MAXN][MAXN];
bool vis[MAXN];
int n, m, t, st[MAXN], ed[MAXN], val[MAXN][MAXN];
int ex[MAXM], ey[MAXM], ez[MAXM];
struct Node{
    int d, x;
    Node(int _d, int _x) : d(_d), x(_x) {}

    bool operator < (const Node& rhs) const{
        return d > rhs.d;
    }
};

inline void add(int u, int v, int t){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = t; h[u] = cnt;
}
inline void dij(int s){
    memset(vis, 0, sizeof vis);
    priority_queue<Node> q;
    q.push(Node(0, s));
    d[s][s] = 0;
    while(!q.empty()){
        auto tp = q.top(); q.pop();
        if(vis[tp.x]) continue;
        vis[tp.x] = true;
        for(int e = h[tp.x]; e; e = nex[e]){
            int v = to[e];
            if(d[s][v] > d[s][tp.x] + w[e]){
                d[s][v] = d[s][tp.x] + w[e];
                q.push(Node(d[s][v], v));
            }
        }
    }
}


int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        val[x][y] = val[y][x] = z;
        ex[i] = x; ey[i] = y; ez[i] = z;
        add(x, y, z);
        add(y, x, z);
    }
    for(int i = 1; i <= t; i++)
        cin >> st[i] >> ed[i];
    memset(d, INF, sizeof d);
    long long ans = INF;
    for(int i = 1; i <= n; i++)
        dij(i);
    for(int i = 1; i <= m; i++){
        long long tmp = 0;
        for(int j = 1; j <= t; j++){
            tmp += min(d[st[j]][ed[j]], min(d[st[j]][ex[i]]+d[ey[i]][ed[j]], d[st[j]][ey[i]]+d[ex[i]][ed[j]]));
        }
        // cout << tmp << endl;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    // cin.get();
    // cin.get();
    return 0;
}