#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 100, M = 4e4 + 100, K = 15;

int h[N], to[M], nex[M], w[M], cnt, n, m;
int fa[N][K], dis[N], dep[N];

void add(int u, int v, int z){
    to[++cnt] = v; w[cnt] = z; nex[cnt] = h[u]; h[u] = cnt;
}


void dfs(int u, int ls){
    for(int e = h[u]; e; e = nex[e]){
        int v = to[e];
        if(v == ls) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dis[v] = dis[u] + w[e];
        dfs(v, u); 
    }
}

void init(){
    for(int i = 1; i < K; i++)
        for(int j = 1; j <= n; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
}

int lca(int x, int y){
    if(dep[y] < dep[x]) swap(x, y);
    int t = dep[y] - dep[x];
    for(int i = 0; i < K; i++){
        if(t & (1 << i)) y = fa[y][i];
    }
    if(x == y) return x;
    for(int i = K - 1; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x == y) return x;
    return fa[x][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, -1);
    init();
    while(m--){
        int x, y;
        cin >> x >> y;
        int l = lca(x, y);
        cout << dis[x] + dis[y] - 2 * dis[l] << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}