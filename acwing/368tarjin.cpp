#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 100050, M = 300005;

int h[N], to[M], nex[M], w[M], cnt, n, m;
int h1[N], to1[M], nex1[M], w1[M], cnt1;
int dfn[N], low[N], st[N], top, timer;
int id[N], tot[N], ind[N], scc_cnt;
bool ins[N];

void add(int u, int v, int z){ 
    to[++cnt] = v; nex[cnt] = h[u]; w[cnt] = z; h[u] = cnt;
}

void add1(int u, int v, int z){
    to1[++cnt1] = v; nex1[cnt1] = h1[u]; w1[cnt1] = z; h1[u] = cnt1;
}

void tarjin(int u){
    dfn[u] = low[u] = ++timer;
    st[++top] = u;
    ins[u] = true;
    for(int e = h[u]; e; e = nex[e]){
        int v = to[e];
        if(!dfn[v]){
            tarjin(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        scc_cnt++;
        int y;
        do{
            y = st[top--];
            id[y] = scc_cnt;
            ins[y] = false;
            tot[scc_cnt]++;
        } while(y != u);
    }
}

LL topsort(){
    queue<int> q;
    LL dis[N];
    memset(dis, 0, sizeof dis);
    for(int i = 1; i <= scc_cnt; i++) if(!ind[i]) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int e = h1[u]; e; e = nex1[e]){
            int v = to1[e];
            if(dis[v] < dis[u] + w1[e])
                dis[v] = dis[u] + w1[e];
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    }
    LL ans = 0;
    for(int i = 1; i <= scc_cnt; i++)
        ans += dis[i] * tot[i];
    return ans;
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1, k, a, b; i <= m; i++){
        scanf("%d%d%d", &k, &a, &b);
        if(k == 1) add(a, b, 0), add(b, a, 0);
        if(k == 2) add(a, b, 1);
        if(k == 3) add(b, a, 0);
        if(k == 4) add(b, a, 1);
        if(k == 5) add(a, b, 0);
    }
    for(int i = 1; i <= n; i++) add(0, i, 1);
    for(int i = 0; i <= n; i++)
        if(!dfn[i]) tarjin(i);

    for(int i = 0; i <= n; i++)
        for(int e = h[i]; e; e = nex[e]){
            int j = to[e];
            int a  = id[i], b = id[j];
            if(a == b && w[e] > 0){
                cout << -1 << endl;
                return 0;
            }
            if(a != b){
                add1(a, b, w[e]);
                ind[b]++;
            }
        }
    cout << topsort() << endl;
    cin.get();
    cin.get();
    return 0;
}