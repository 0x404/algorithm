#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, INF = 1e13;

LL dp[N][3], a[N], n;



int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = -INF;
    
    dp[1][1] = -a[1];
    dp[1][2] = 0;
    for(int i = 2; i <= n; i++){
        dp[i][1] = max(dp[i-1][1], dp[i-1][2] - a[i]);
        dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i]);
        dp[i][2] = max(dp[i-1][0], dp[i-1][2]);
    }
    cout << max(dp[n][0], dp[n][2]) << endl;
    
    return 0;
}