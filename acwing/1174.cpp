#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 100, M = 5e4 + 100;

int h[N], to[M], nex[M], cnt, n, m;
int low[N], dfn[N], st[N], top;
int id[N], tot[N], scc_cnt, timer;
bool ins[N];
int outd[N];
void add(int u, int v){
    to[++cnt] = v; nex[cnt] = h[u]; h[u] = cnt;
}

void tarjin(int u){
    low[u] = dfn[u] = ++timer;
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
    if(dfn[u] == low[u]){
        scc_cnt++;
        int y;
        do{
            y = st[top];
            top--;
            id[y] = scc_cnt;
            ins[y] = false;
            tot[scc_cnt]++;
        } while(y != u);
    }
}

void rebuild(){
    for(int i = 1; i <= n; i++)
        for(int e = h[i]; e; e = nex[e]){
            int a = id[i];
            int b = id[to[e]];
            if(a != b) outd[a]++;
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjin(i);
    rebuild();
    int k = 0;
    int ans = 0;
    for(int i = 1; i <= scc_cnt; i++)
        if(outd[i] == 0){
            ans = tot[i];
            k++;
        }
    if(k == 1) cout << ans << endl;
    else cout << 0 << endl;
    cin.get();
    cin.get();
    return 0;
}