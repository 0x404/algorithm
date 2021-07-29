#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000500;

int primes[N], cnt;
int p[N], tot;
bool st[N], vis[N];


void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[++cnt] = i;
        for(int j = 1; j <= cnt && primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}


int main(){
    init(50000);
    LL l, r;
    while(cin >> l >> r){
        memset(vis, 0, sizeof vis);
        memset(p, 0, sizeof p);
        tot = 0;
        for(int i = 1; i <= cnt; i++){
            LL l0 = (l % primes[i] == 0) ? l / primes[i] : l / primes[i] + 1;
            LL r0 = (r % primes[i] == 0) ? r / primes[i] : r / primes[i];
            for(LL k = l0 == 1 ? 2 : l0; k <= r0; k++)
                vis[k * primes[i] - l] = true;
        }
        for(LL i = l == 1 ? 2 : l; i <= r; i++)
            if(!vis[i - l]) p[++tot] = i;
        if(tot < 2)
            cout << "There are no adjacent primes." << endl;
        else{
            LL ans1, ans2, ans3, ans4, minp = 5e9, maxp = 0;
            for(int i = 1; i < tot; i++){
                if(p[i + 1] - p[i] < minp){
                    minp = p[i + 1] - p[i];
                    ans1 = p[i];
                    ans2 = p[i + 1];
                }
                if(p[i + 1] - p[i] > maxp){
                    maxp = p[i + 1] - p[i];
                    ans3 = p[i];
                    ans4 = p[i + 1];
                }
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", ans1, ans2, ans3, ans4);
        }
    }
    cin.get();
    cin.get();
    return 0;
}