#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 99999999

using namespace std;

const int N = 200;

int e[N][N];
double d[N][N], x[N], y[N], maxD[N];
int n;


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1') e[i][j+1] = 1;
            else e[i][j+1] = 0;
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = INF;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(e[i][j])
                d[i][j] = min(d[i][j], sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
            if(i == j) d[i][j] = d[j][i] = 0;
        }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(d[i][j] != INF) maxD[i] = max(maxD[i], d[i][j]);

    double ans = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(d[i][j] == INF && d[j][i] == INF){
                double d1 = 0, d2 = 0;
                for(int k = 1; k <= n; k++)
                    if(d[i][k] != INF) d1 = max(d1, maxD[k]);
                for(int k = 1; k <= n; k++)
                    if(d[j][k] != INF) d2 = max(d2, maxD[k]);
                double d3 = maxD[i] + maxD[j] + sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                ans = min(ans, max(d3, max(d1, d2)));
            }
    printf("%.6f", ans);
    // cin.get();
    // cin.get();
    return 0;
}