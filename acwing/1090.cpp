#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 5e4 + 100;

int a[N], f[N], n, t;

bool check(int m){
    memset(f, 0, sizeof f);
    deque<int> q;
    q.push_back(0);
    for(int i = 1; i <= n; i++){
        while(!q.empty() && q.front() < i - m) q.pop_front();
        f[i] = f[q.front()] + a[i];
        while(!q.empty() && f[i] <= f[q.back()]) q.pop_back();
        q.push_back(i);
    }
    int ans = f[n];
    for(int i = n - m + 1; i <= n; i++) ans = min(ans, f[i]);
    return ans <= t;
}


int main(){
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r << endl;
    // cin.get();
    // cin.get();
    return 0;
}