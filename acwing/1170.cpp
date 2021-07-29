#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;

typedef long long LL;

const int N = 1050, M = 100000;

int h[N], to[M], nex[M], w[M], cnt, n, m, k;
LL dis[N], tot[N];
bool vis[N];

void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

bool spfa(int s){
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    memset(tot, 0, sizeof tot);
    dis[s] = 0;
    vis[s] = true;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); 
        q.pop(), vis[u] = false;
        for(int e = h[u]; e; e = nex[e]){
            int v = to[e];
            if(dis[v] > dis[u] + w[e]){
                dis[v] = dis[u] + w[e];
                tot[v]++;
                if(tot[v] >= n + 1) return false;
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
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y ,z);
    }
    for(int i = 1; i <= k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        add(y, x, -z);
    }
    for(int i = 2; i <= n; i++)
            add(i, i - 1, 0);
    if(!spfa(1)){
        // for(int i = 0; i <= n; i++) cout << dis[i] << " "; cout << endl;
        cout << -1 << endl;
        return 0;
    }
    if(dis[n] >= 1e9){
        bool f = false;
        for(int i = 2; i <= n; i++){
            if(!spfa(i)){
                
                f = true;
                break;
            }
            // for(int i = 1; i <= n; i++)
            //     cout << tot[i] << " "; cout << endl;
        }
        if(f) cout << -1 << endl;
        else cout << -2 << endl;
        return 0;
    }
    cout << dis[n] << endl;
    cin.get();
    cin.get();
    return 0;
}