#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10;

LL f[N][N*N][M], n, k; 
vector<int> state;
vector<int> trance[M + 10];
int cnt[M + 10];
bool check(int s){
    for(int i = 0; i < (n-1); i++)
        if(((s >> i) & 1) && ((s >> (i+1)) & 1)) return false;
    return true;
}
int cal(int s){
    int ans = 0;
    while(s){
        if(s & 1) ans++;
        s >>= 1;
    }
    return ans;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i < (1 << n); i++)
        if(check(i)) state.push_back(i);
    for(int i = 0; i < state.size(); i++)
        for(int j = 0; j < state.size(); j++){
            int a = state[i];
            int b = state[j];
            if((a & b) == 0 && check(a | b)) trance[a].push_back(b);
        }
    for(int i = 0; i < state.size(); i++)
        cnt[state[i]] = cal(state[i]);
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(auto a : state)
                for(auto b : trance[a]){
                    if(j >= cnt[a]) f[i][j][a] += f[i-1][j - cnt[a]][b];
                }
    long long ans = 0;
    for(auto s : state) ans += f[n][k][s];
    cout << ans << endl;
    // cin.get();
    // cin.get();
    return 0;
}
