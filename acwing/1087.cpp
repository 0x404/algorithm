#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 100;

typedef long long LL;

int a[N], n, k;
LL sum[N], f[N], ans;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    deque<int> q;
    for(int i = 1; i <= k; i++){
        f[i] = sum[i];
        ans = max(ans, f[i]);
        while(i > 1 && !q.empty() && f[i - 1] - sum[i] >= f[q.back()] - sum[q.back() + 1]) q.pop_back();
        if(i > 1) q.push_back(i - 1);
    }
    for(int i = k + 1; i <= n; i++){
        while(!q.empty() && q.front() < i - k - 1) q.pop_front();

        f[i] = q.empty() ? a[i] : f[q.front()] - sum[q.front() + 1] + sum[i];
        ans = max(ans, f[i]);
        while(!q.empty() && f[i - 1] - sum[i] >= f[q.back()] - sum[q.back() + 1]) q.pop_back();
        q.push_back(i - 1);
    }
    cout << ans << endl;

    return 0;
}