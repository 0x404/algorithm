#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

typedef long long LL;

const int N = 13, M = 1 << 11;

LL f[N][M];
bool valid[N][M];
int x[N];
int n, m;



bool check(int s, int m){
    for(int i = 0; i < m; i++)
        x[i] = ((s >> i) & 1);
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(x[i] == 0) cnt++;
        if(x[i] == 1 && cnt & 1) return false;
        if(x[i] == 1) cnt = 0;
    }
    if(cnt & 1) return false;
    return true;
}


int main(){

    for(int i = 1; i < N; i++)
        for(int j = 0; j < M; j++)
            valid[i][j] = check(j, i);

    while(cin >> n >> m && n && m){
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < (1 << m); j++)
                for(int s = 0; s < (1 << m); s++){
                    if((s & j) == 0 && valid[m][s | j]) f[i][j] += f[i-1][s];
                }
        printf("%lld\n", f[n][0]);
    }
    return 0;
}