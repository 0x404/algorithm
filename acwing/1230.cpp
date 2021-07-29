#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100050;

int cnt[N], a[N], n, k;
LL sum[N];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    LL ans = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= k;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans << endl;
    return 0;
}