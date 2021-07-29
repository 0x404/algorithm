#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

string s, t;
int n, cases, f[N][2][2];

int dfs(int x, int state, int dir){
    if(f[x][state][dir] != -1) return f[x][state][dir];
    if(state & 1){
        if(dir == 0){
            if(t[x - 1] == 'R') return f[x][state][dir] = 0;
            if(t[x - 1] == 'L'){
                int res = dfs(x - 1, 1 - state, 0);
                return f[x][state][dir] = res + 1;
            }
        }
        if(dir == 1){
            if(t[x] == 'L') return f[x][state][dir] = 0;
            if(t[x] == 'R'){
                int res = dfs(x + 1, 1 - state, 1);
                return f[x][state][dir] = res + 1;
            }
        }
    }
    else{
        if(dir == 0){
            if(s[x - 1] == 'R') return f[x][state][dir] = 0;
            if(s[x - 1] == 'L'){
                int res = dfs(x - 1, 1 - state, 0);
                return f[x][state][dir] = res + 1;
            }
        }
        if(dir == 1){
            if(s[x] == 'L') return f[x][state][dir] = 0;
            if(s[x] == 'R'){
                int res = dfs(x + 1, 1 - state, 1);
                return f[x][state][dir] = res + 1;
            }
        }
    }
}


int main(){
    cin >> cases;
    while(cases--){
        cin >> n >> s;
        t = "";
        for(int i = 0; i < s.length(); i++)
            t += s[i] == 'L' ? 'R' : 'L';
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= 1; j++)
                for(int k = 0; k <= 1; k++)
                    f[i][j][k] = -1;
        f[0][0][0] = f[0][1][0] = f[n][0][1] = f[n][1][1] = 0;
        for(int i = 0; i <= n; i++){
            if(i == 0){
                if(s[0] == 'R') cout << 2 + dfs(i + 1, 1, 1) << " ";
                else cout << 1 << " ";
                continue;
            }
            if(i == n){
                if(s[n - 1] == 'L') cout << 2 + dfs(i - 1, 1, 0) << endl;
                else cout << 1 << endl;
                continue;
            }
            int ans = 1;
            if(s[i - 1] == 'L') ans += dfs(i - 1, 1, 0) + 1;
            if(s[i] == 'R') ans += dfs(i + 1, 1, 1) + 1;
            cout << ans << " ";
        }
    }
    // cin.get();
    // cin.get();
    return 0;
}