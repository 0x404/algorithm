#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

const int N = 12, P = 120, M = 1000, S = 1 << N;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

struct Node{
    int x, state, d;

    bool operator < (const Node &rhs) const{
        return d > rhs.d;
    }

    Node(int _x, int _state, int _d) : x(_x), state(_state), d(_d) {}

};

int id[N][N], key[P], n, m, p, tot;
int h[P], to[M], nex[M], w[M], cnt;
int limit[P][P], conneted[P][P], dis[P][S];
bool vis[P][S];

bool valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

int dij(){
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<Node> heap;
    dis[1][0] = 0;
    heap.push(Node(1, 0, 0));
    while(!heap.empty()){
        auto now = heap.top(); heap.pop();
        if(vis[now.x][now.state]) continue;
        vis[now.x][now.state] = true;
        if(now.x == id[n][m]) return now.d;

        if(key[now.x] && dis[now.x][now.state | key[now.x]] > dis[now.x][now.state]){
            dis[now.x][now.state | key[now.x]] = dis[now.x][now.state];
            heap.push(Node(now.x, now.state | key[now.x], now.d));
        }

        for(int e = h[now.x]; e; e = nex[e]){
            int v = to[e];
            if(w[e] == 0 && dis[v][now.state] > now.d + 1){
                dis[v][now.state] = now.d + 1;
                heap.push(Node(v, now.state, now.d +1));
            }
            else if(w[e] != 0 && (now.state & w[e]) != 0 && dis[v][now.state] > now.d + 1){
                dis[v][now.state] = now.d + 1;
                heap.push(Node(v, now.state, now.d +1));
            }
        }
    }
    return -1;
}


int main(){
    
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            id[i][j] = ++tot;
    int k;
    cin >> k;
    while(k--){
        int x1, y1, x2, y2, g;
        cin >> x1 >> y1 >> x2 >> y2 >> g;
        limit[id[x1][y1]][id[x2][y2]] = limit[id[x2][y2]][id[x1][y1]] = (g == 0 ? -1 : (1 << g));
    }
    cin >> k;
    while(k--){
        int x, y, z;
        cin >> x >> y >> z;
        key[id[x][y]] |= (1 << z);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(!valid(nx, ny)) continue;
                int u = id[i][j];
                int v = id[nx][ny];
                if(limit[u][v] != -1 && !conneted[u][v]){
                    add(u, v, limit[u][v]);
                    add(v, u, limit[u][v]);
                    conneted[u][v] = conneted[v][u] = 1;
                }

            }
    cout << dij() << endl;
    cin.get();
    cin.get();
    return 0;
}