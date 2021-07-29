#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 105, M = 1 << 10;
vector<int> state;
vector<int> validSt[N];
int cnt[M + 10], f[3][M][M], raw[N], tmp[15], n, m;

bool check(int s){
    for(int i = 0; i < m; i++) tmp[i] = ((s >> i) & 1);
    for(int i = 0; i < m; i++){
        if(i + 1 < m && tmp[i] == 1 && tmp[i+1] == 1) return false;
        if(i + 2 < m && tmp[i] == 1 && tmp[i+2] == 1) return false;
    }
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
    cin >> n >> m;    
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        int st = 0;
        for(int j = 0; j < s.length(); j++)
            if(s[j] == 'H') st += (1 << j);
        raw[i] = st;
    }

    for(int i = 0; i < (1 << m); i++)
        if(check(i)) state.push_back(i);

    for(auto s : state) cnt[s] = cal(s);

    for(int i = 1; i <= n; i++)
        for(auto s : state)
            if((s & raw[i]) == 0) validSt[i].push_back(s);
    validSt[0].push_back(0);
    for(auto s : validSt[1]) f[0][s][0] = cnt[s];
    for(auto a : validSt[2])
        for(auto b : validSt[1])
            if((a & b) == 0) f[1][a][b] = cnt[a] + cnt[b];
    for(int i = 3; i <= n; i++)
        for(auto a : validSt[i])
            for(auto b : validSt[i-1]){
                if(b & a) continue;
                for(auto c : validSt[i-2]){
                    if((b & c) || (a & c)) continue;
                    int now = (i - 1) % 3;
                    int ls = (i + 1) % 3;
                    f[now][a][b] = max(f[now][a][b], f[ls][b][c] + cnt[a]);
                }
            }
    int ans = 0;
    for(auto a : state)
        for(auto b : state)
            ans = max(ans, f[(n-1)%3][a][b]);

    cout << ans << endl;
    // cin.get();
    // cin.get();
    return 0;
}   
