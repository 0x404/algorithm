#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10000;

int h[N], to[N], nex[N], w[N], cnt;
int dfn[N], low[N], st[N], timer, n, m, top;
int id[N], scc_cnt, ind[N], outd[N];
bool ins[N];



void add(int u, int v){
    to[++cnt] = v; nex[cnt] = h[u]; h[u] = cnt;
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
        int y;
        scc_cnt++;
        do{
            y = st[top--];
            ins[y] = false;
            id[y] = scc_cnt;
        } while(top > 0 && y != u);
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        while(cin >> t, t) add(i, t);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjin(i);
    for(int i = 1; i <= n; i++)
        for(int e = h[i]; e; e = nex[e]){
            int j = to[e];
            int a = id[i];
            int b = id[j];
            if(a != b){
                outd[a]++;
                ind[b]++;
            }
        }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= scc_cnt; i++){
        if(ind[i] == 0) ans1++;
        if(outd[i] == 0) ans2++;
    }
    ans2 = max(ans1, ans2);
    cout << ans1 << endl;
    cout << (scc_cnt == 1 ? 0 : ans2) << endl;
    // cin.get();
    // cin.get();
    return 0;
}
