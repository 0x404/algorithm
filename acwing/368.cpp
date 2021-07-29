#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100005, M = 1e6;

int h[N], to[M], nex[M], w[M], cnt, n, m;
int dis[N], inq[N];
bool vis[N];
void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

bool spfa(){
    queue<int> q; while(!q.empty()) q.pop();
    q.push(0);
    vis[0] = true;
    dis[0] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop(); vis[now] = false;
        for(int e = h[now]; e ; e = nex[e]){
            int v = to[e];
            if(dis[now] + w[e] > dis[v]){
                dis[v] = dis[now] + w[e];
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    
    return true;
}

int main(){ 
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> c >> a >> b;
        switch(c){
            case 1 :
                add(a, b, 0);
                add(b, a, 0);
                break;
            case 2 :
                add(a, b, 1);
                break;
            case 3 :
                add(b, a, 0);
                break;
            case 4 :
                add(b, a, 1);
                break;
            case 5 :
                add(a, b, 0);
                break;
        }
    }
    for(int i = 1; i <= n; i++)
        add(0, i, 1);
    if(!spfa()){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += dis[i];
    cout << ans << endl;
    cin.get();
    cin.get();
    return 0;
}