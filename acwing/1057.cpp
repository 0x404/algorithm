#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, K = 105;
const int INF = 1e13;

int w[N], n, k;
LL dp[2][K][2];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < K; j++)
            dp[i][j][0] = dp[i][j][1] = -INF;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++){
            int now = i & 1;
            int ls = (i - 1) & 1;
            dp[now][j][0] = max(dp[now][j][0], dp[ls][j][0]);
            dp[now][j][0] = max(dp[now][j][0], dp[ls][j][1] + w[i]);
            if(j >= 1){
                dp[now][j][1] = max(dp[now][j][1], dp[ls][j][1]);
                dp[now][j][1] = max(dp[now][j][1], dp[ls][j - 1][0] - w[i]);
            }
        }
    LL ans = 0;
    for(int i = 0; i <= k; i++) ans = max(ans, dp[n & 1][i][0]);
    cout << ans << endl;
    
    return 0;
}