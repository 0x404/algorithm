#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;

const int N = 1e6 + 100;

LL o[2 * N], d[2 * N], n;
LL sum[2 * N];
bool valid[N];
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> o[i] >> d[i];
    for(int i = n + 1; i <= 2 * n; i++)
        o[i] = o[i - n], d[i] = d[i - n];
    for(int i = 2; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + o[i - 1] - d[i - 1];

    deque<int> q;
    for(int i = 2; i <= n + 1; i++){
        while(!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
        q.push_back(i);
    }
    if(sum[q.front()] >= 0) valid[1] = true;
    for(int i = n + 2; i <= n + n; i++){
        while(!q.empty() && q.front() <= i - n) q.pop_front();
        while(!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
        q.push_back(i);
        if(sum[q.front()] - sum[i - n] >= 0) valid[i - n] = true;
    }

    q.clear();
    reverse(o + 1, o + 1 + n + n);
    for(int i = 1; i <= n - 1; i++)
        d[i] = d[n + n - i];
    for(int i = n + 1; i <= n + n; i++)
        d[i] = d[i - n];
    for(int i = 2; i <= 2 * n; i++)
        sum[i] = sum[i - 1] + o[i - 1] - d[i - 1];
    for(int i = 2; i <= n + 1; i++){
        while(!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
        q.push_back(i);
    }
    if(sum[q.front()] >= 0) valid[n] = true;
    for(int i = n + 2; i <= n + n; i++){
        while(!q.empty() && q.front() <= i - n) q.pop_front();
        while(!q.empty() && sum[i] <= sum[q.back()]) q.pop_back();
        q.push_back(i);
        if(sum[q.front()] - sum[i - n] >= 0) valid[2*n - i +1] = true;
        // cout << 2 * n - i + 1 << " : " << sum[q.front()] << " " << sum[i - n] << endl;
    }

    for(int i = 1; i <= n; i++)
        if(valid[i]) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    cin.get();
    cin.get();
    return 0;
    
}