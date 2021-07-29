#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int N = 30;

int d[N][N], g[N][N], n, m;

bool floyd(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            g[i][j] = d[i][j];
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] |= (g[i][k] && g[k][j]);
}

int check(int t){
    for(int i = 1; i <= n; i++)
        if(g[i][i]){
            printf("Inconsistency found after %d relations.\n", t);
            return 1;
        }
    
    int vis[N];
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        int k = 0;
        for(int j = 1; j <= n; j++)
            if(g[i][j]) k++;
        vis[k] = i;
    }
    for(int i = 0; i <= n - 1; i++)
        if(!vis[i]) return 2;
    
    printf("Sorted sequence determined after %d relations: ", t);
    for(int i = n - 1; i >= 0; i--){
        char ot = 'A' + vis[i] - 1;
        printf("%c", ot);
    }
        
    cout << "." << endl;
    return 3;
}

int main(){

    while(cin >> n >> m && n && m){
        memset(d, 0, sizeof d);
        bool finished = false;

        for(int i = 1; i <= m; i++){
            char x, y, c;
            cin >> x >> c >> y;
            if(finished) continue;
            d[x - 'A' + 1][y - 'A' + 1] = 1;
            floyd();
            int res = check(i);
            if(res == 1 || res == 3){
                finished = true;
                continue;
            }
        } 
        if(!finished) cout << "Sorted sequence cannot be determined." << endl;
    }

    // cin.get();
    // cin.get();
    return 0;
}