#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL t, n, k;

bool check(LL mid){
    if(n * mid < k) return false;
    int res = n * mid % k;
    if((n - 1) * (mid - 1) >= res) return true;
    return false;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        LL l = 1, r = k;
        while(l <= r){
            LL mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}