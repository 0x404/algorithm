#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 200005, M = 300005;

LL h[N], to[M], nex[M], w[M], cnt, n, m;
LL dis[N], inq[N];
bool ins[N];
int q[N];//queue
void add(int u, int v, int z){
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

bool spfa(){
    int hh = 0, tt = 1;
    q[0] = 0;
    ins[0] = true;
    dis[0] = 0;
    while(hh != tt){
        int u = q[--tt]; ins[u] = false;
       
        for(int e = h[u]; e; e = nex[e]){
            int v = to[e];
            if(dis[v] < dis[u] + w[e]){
                dis[v] = dis[u] + w[e];
                inq[v]++;
                if(inq[v] > n) return false;
                if(!ins[v]){
                    ins[v] = true;
                    q[tt++] = v;
                    // if(tt == N - 1) tt = 0;
                    // if(hh == N - 1) hh = 0;
                }
            }
        }
    }
    return true;
}

int main(){ 
    scanf("%d%d", &n, &m);
    int a, b, c;
    for(int i = 1; i <= m; i++){
        cin >> c >> a >> b;
        // scanf("%d%d%d", &c, &a, &b);
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
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}