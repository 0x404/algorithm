#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 300050;

LL sum[N];
int a[N], n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    deque<int> q; 
    q.push_back(0);
    LL ans = a[1];
    for(int i = 1; i <= n; i++){
        while(!q.empty() && q.front() < i - m) q.pop_front();
        ans = max(ans, sum[i] - sum[q.front()]);
        while(!q.empty() && sum[q.back()] >= sum[i]) q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    cin.get();
    cin.get();
    return 0;
}