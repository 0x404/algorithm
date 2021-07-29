#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int h[N], to[M], nex[M], cnt;
int h1[N], to1[M], nex1[M], cnt1;
int low[N], dfn[N], st[N], id[N], value[N], top, timer, n, m, scc_cnt, mod;
bool ins[N];

int f[N], g[N], ind[N], outd[N];


void add(int u, int v){
    to[++cnt] = v; nex[cnt] = h[u]; h[u] = cnt;
}

void add1(int u, int v){
    to1[++cnt1] = v; nex1[cnt1] = h1[u]; h1[u] = cnt1; 
}

void tarjin(int u){
    low[u] = dfn[u] = ++timer;
    st[++top] = u, ins[u] = true;
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
        int y;
        scc_cnt++;
        do{
            y = st[top--];
            id[y] = scc_cnt;
            ins[y] = false;
            value[scc_cnt]++;
        } while(y != u);
    }
}

void topsort(){
    queue<int> q;
    for(int i = 1; i <= scc_cnt; i++)
        if(ind[i] == 0) f[i] = value[i], g[i] = 1, q.push(i);
    while(q.size()){
        int ft = q.front(); q.pop();
        for(int e = h1[ft]; e; e = nex1[e]){
            int v = to1[e];
            if(f[ft] + value[v] > f[v]){
                f[v] = f[ft] + value[v];
                g[v] = g[ft];
            }
            else if(f[ft] + value[v] == f[v]){
                g[v] = (g[v] + g[ft]) % mod;
            }
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    }


    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= scc_cnt; i++){
        if(f[i] > ans1){
            ans1 = f[i];
            ans2 = g[i];
        }
        else if(f[i] == ans1){
            ans2 = (ans2 + g[i]) % mod;
        }
    }
    cout << ans1 << endl << ans2 << endl;
}

int main(){
    cin >> n >> m >> mod;
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjin(i);
    set<PII> s;
    for(int i = 1; i <= n; i++)
        for(int e = h[i]; e; e = nex[e]){
            int j = to[e];
            int a = id[i], b = id[j];
            if(a != b && s.find(make_pair(a, b)) == s.end()){
                s.insert(make_pair(a, b));
                add1(a, b);
                ind[b]++;
                outd[a]++;
            }           
        }
    topsort();
    // cin.get();
    // cin.get();
    return 0;
}