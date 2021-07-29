#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 220;

int w[N][N], f[N][N], ans[N][N];
int m, K, s, e, n;
bool flag = false;
map<int, int> mp;

void multiAns(){
    if(!flag){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans[i][j] = f[i][j];
    }
    else{
        int tmp[N][N];
        memset(tmp, 0x3f, sizeof tmp);
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    tmp[i][j] = min(tmp[i][j], ans[i][k] + f[k][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                ans[i][j] = tmp[i][j];
    }

}
void multif(){
    int tmp[N][N];
    memset(tmp, 0x3f, sizeof tmp); 
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                tmp[i][j] = min(tmp[i][j], f[i][k] + f[k][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = tmp[i][j];
}

int main(){
    cin >> K >> m >> s >> e;
    memset(w, 0x3f, sizeof w);
    memset(ans, 0x3f, sizeof ans);
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(mp.count(b) == 0) mp[b] = ++n;
        if(mp.count(c) == 0) mp[c] = ++n;
        b = mp[b];
        c = mp[c];
        w[b][c] = w[c][b] = min(w[b][c], a);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            f[i][j] = w[i][j];
    
    while(K){
        if(K & 1){
            multiAns();
            if(!flag) flag = true;
        }
        multif();
        K >>= 1;
    }
    cout << ans[mp[s]][mp[e]] << endl;
    
    cin.get();
    cin.get();
    return 0;
}