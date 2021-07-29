#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100005, M = 2500000;

int trie[M][2], cnt, n;
int id[M];
LL a[N], sum[N];

void insert(LL x, int k){
    int now = 0;
    for(int i = 21; i >= 0; i--){
        int u = (x >> i) & 1;
        if(!trie[now][u])
            trie[now][u] = ++cnt;
        now = trie[now][u];
    }
    id[now] = k;
}

LL search(LL x){
    int now = 0;
    for(int i = 21; i >= 0; i--){
        int u = (x >> i) & 1;
        if(trie[now][1 - u]) now = trie[now][1 - u];
        else now = trie[now][u];
    }
    return id[now];
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    insert(sum[0], 0);
    int ans = -1, l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        int k = search(sum[i]);
        int res = sum[i] ^ sum[k];
        if(res > ans){
            ans = res;
            l = k;
            r = i;
        }
        insert(sum[i], i);
    }
    cout << ans << " " << l + 1 << " " << r << endl;
    // cin.get();
    // cin.get();
    return 0;
}