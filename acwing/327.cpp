#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 14, M = 1 << 12, MOD = 100000000;

LL f[N][M], n, m;
vector<int> state;
int raw[N];

bool check(int s){
    for(int i = 0; i < (m - 1); i++)
        if(((s >> i) & 1) && ((s >> (i + 1)) & 1)) return false;
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < (1 << m); i++)
        if(check(i)) state.push_back(i);
    for(int i = 1; i <= n; i++){
        int s = 0, x;
        for(int j = 0; j < m; j++){
            cin >> x;
            x = x == 1 ? 0 : 1;
            s += (x << j);
        }
        raw[i] = s;
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(auto j : state){
            if(raw[i] & j) continue;
            for(auto k : state){
                if(j & k) continue;
                f[i][j] = (f[i][j]%MOD + f[i-1][k]%MOD)%MOD;
            }
        }
    LL ans = 0;
    for(auto s : state) ans = (ans % MOD + f[n][s] % MOD) % MOD;
    cout << ans << endl;
    
    return 0;
}


