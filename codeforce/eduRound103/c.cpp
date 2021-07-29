#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL t, n, c[N], a[N], b[N];
LL f[N];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) f[i] = 0;
        for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%lld", &b[i]);
        LL ans = 0;
        for(int i = 2; i <= n; i++){
            LL high = min(a[i], b[i]);
            LL low = max(a[i], b[i]);
            if(high == low) f[i] = c[i] + 1;
            else{
                f[i] = c[i] + 1 + low - high;
                f[i] = max(f[i], f[i - 1] - (low - high) + c[i] + 1);
            } 
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}