#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 999999999999999

using namespace std;

typedef long long LL;

const int N = 55;


LL dp[N][N], w[N], n;


LL dfs(int l, int r){
    if(dp[l][r] != INF) return dp[l][r];

    if(r - l + 1 < 3)
        return dp[l][r] = 0;

    if(r - l + 1 == 3)
        return dp[l][r] = w[l] * w[l+1] * w[r];
        
    for(int k = l + 1; k < r; k++)
        dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k, n) + w[l] * w[k] * w[r]);
    return dp[l][r];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = INF;


    cout << dfs(1, n) << endl;
    
    return 0;
}