#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 305, M = 100000;

int u[M], v[M], w[M], cnt, n;
int rk[M], f[N];

void push(int x, int y, int z){
    cnt++;
    u[cnt] = x, v[cnt] = y, w[cnt] = z;
}

bool cmp(int a, int b){
    return w[a] < w[b];
}

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        push(0, i, x);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(i == j) continue;
            push(i, j, x);
        }
    for(int i = 1; i <= cnt; i++) rk[i] = i;
    for(int i = 0; i <= n; i++) f[i] = i;
    sort(rk + 1, rk + 1 + cnt, cmp);
    int connect = 0, ans = 0;
    for(int i = 1; i <= cnt; i++){
        int x = u[rk[i]];
        int y = v[rk[i]];
        int fx = find(x);
        int fy = find(y);
        if(fx != fy){
            ans += w[rk[i]];
            f[fx] = fy;
            connect++;
        }
        if(connect == n) break;
    }   
    cout << ans << endl;
    return 0;
}