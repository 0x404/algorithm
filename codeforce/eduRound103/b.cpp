#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

typedef long long LL;

const int N = 150;

LL n, t, k;
LL p[N], sum[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(sum, 0, sizeof sum);
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i];
        LL ans = 0;
        for(int i = n; i > 1; i--){
            LL tar = 100 * p[i];
            if(tar % k == 0) tar = tar / k;
            else tar = tar / k + 1;
            ans = max(ans, tar - sum[i - 1]);
        }
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}