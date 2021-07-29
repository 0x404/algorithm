#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 50000000

using namespace std;

const int N = 105, M = 10050;

int d[N][N], w[N][N], pos[N][N], ansPos[N][N];
int n, m, ans = INF;
vector<int> path;

void savePath(int l, int r, int mid){
    if(pos[l][mid])
        savePath(l, mid, pos[l][mid]);
    path.push_back(mid);
    if(pos[mid][r])
        savePath(mid, r, pos[mid][r]);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = INF;
    for(int i = 1; i <= m; i++){
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        d[u][v] = d[v][u] = min(d[u][v], l);
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            w[i][j] = d[i][j];
    
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i < k; i++)
            for(int j = 1; j < k; j++){
                if(i != j && w[i][k] + w[k][j] + d[i][j] < ans){
                    // cout << w[i][k] << " " << w[k][j] << " " << d[i][j] << " " << ans << endl;
                    ans = w[i][k] + w[k][j] + d[i][j];
                    
                    // cout << i << " " << k << " " << j << endl;
                    path.clear();
                    if(pos[i][j]) savePath(i, j, pos[i][j]);
                    path.push_back(j);
                    path.push_back(k);
                    path.push_back(i);
                }
            }
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
    }
    // cout << ans << endl;
    if(ans == INF) cout << "No solution." << endl;
    else 
        for(auto x : path) cout << x << " ";
    // cin.get();
    // cin.get();
    return 0;

}