#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 99999999999
using namespace std;

const int N = 1050;

typedef long long LL;

int a[N][N];
int n, m;
LL f[N][N][2], sum[N][N];

inline int  max(int a, int b){return a > b ? a : b;}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
            
    for(int i = 0; i <= m + 1; i++)
        for(int j = 0; j <= n + 1; j++)
            f[i][j][0] = f[i][j][1] = -INF;
    
    f[1][0][0] = 0;
    for(int k = 1; k <= n; k++){
        f[1][k][0] =  f[1][k-1][0] + a[k][1];
    }

    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            LL maxx = max(f[i-1][j][0], f[i-1][j][1]);
            f[i][j][0] = max(f[i][j-1][0], maxx) + a[j][i];
        }
        for(int j = n; j >= 1; j--){
            LL maxx = max(f[i-1][j][0], f[i-1][j][1]);
            f[i][j][1] = max(f[i][j][1], maxx + a[j][i]);
            f[i][j][1] = max(f[i][j][1], f[i][j+1][1] + a[j][i]);
        }
    }

    cout << f[m][n][0] << endl;
    
    return 0;
}