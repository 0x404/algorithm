#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;


int val[N], n;
int dp[N][N], path[N][N];

vector<int> ans;

void dfs(int l, int r){
    int mid = path[l][r];
    ans.push_back(mid);
    if(mid > l)
        dfs(l, mid - 1);
    if(mid < r)
        dfs(mid + 1, r);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];

    for(int i = 1; i <= n; i++)
        dp[i][i] = val[i],
        path[i][i] = i;
    for(int len = 2; len <= n; len++)
        for(int l = 1; l <= n; l++){
            int r = l + len - 1;
            if(r > n) break;
            for(int k = l + 1; k < r; k++){
                if(dp[l][k - 1] * dp[k + 1][r] + val[k] > dp[l][r]){
                    dp[l][r] = dp[l][k - 1] * dp[k + 1][r] + val[k];
                    path[l][r] = k;
                }
            }
            if(dp[l + 1][r] + val[l] > dp[l][r]){
                dp[l][r] = dp[l + 1][r] + val[l];
                path[l][r] = l;
            }
            if(dp[l][r - 1] + val[r] > dp[l][r]){
                dp[l][r] = dp[l][r - 1] + val[l];
                path[l][r] = r;
            }
        }
    dfs(1, n);
    cout << dp[1][n] << endl;
    cout << ans.front();
    for(int i = 1; i < ans.size(); i++)
        cout << " " << ans[i];
    cout << endl;
    // cin.get();
    // cin.get();
    return 0;
}