#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6+10;
const ll mod = 1e9+7;
int t, n;
bool add[maxn];
ll cnt[maxn];
int main()
{
    
    add[1] = add[2] = false;
    cnt[1] = cnt[2] = 0;
    for(int i = 3; i <= maxn-10; i++)
    {
        cnt[i] = (2*cnt[i-2]+cnt[i-1])%mod;
        if(!add[i-2]&&!add[i-1]) cnt[i]+=1, add[i] = true;
        else add[i] = false;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", 4*cnt[n]%mod);
    }
    return 0;
}