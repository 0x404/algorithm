#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 2e5 + 100;

int f[N], a[N], n, m;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = a[1];
    deque<int> q;
    q.push_back(0);
    for(int i = 1; i <= n; i++){
        while(!q.empty() && q.front() < i - m) q.pop_front();
        f[i] = f[q.front()] + a[i];
        while(!q.empty() && f[i] <= f[q.back()]) q.pop_back();
        q.push_back(i);
    }
    int ans = f[n];
    for(int i = n - m + 1; i <= n; i++)
        ans = min(ans, f[i]);
    cout << ans << endl;
    cin.get();
    cin.get();
    return 0;
}