#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, a[N], cnt[N];
int ans[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
        cnt[a[i]]++;
    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            ans[j] += cnt[i];
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[a[i]] - 1);
    return 0;
}