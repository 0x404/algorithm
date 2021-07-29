#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e5 + 100, M = 20;

int a[N], f[N][M], n;

void init(){
    for(int i = 1; i <= n; i++) f[i][0] = a[i];
    for(int i = 1; i < M; i++)
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
}

int query(int l, int r){
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    init();
    int t; cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}