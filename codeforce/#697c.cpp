#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int d1[N], d2[N], n, t, k, m;
int l[N], r[N];

int main(){
    cin >> t;
    while(t--){
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        cin >> n >> m >> k;
        for(int i = 1; i <= k; i++)
            cin >> l[i];
        for(int i = 1; i <= k; i++)
            cin >> r[i];
        for(int i = 1; i <= k; i++){
            d1[l[i]]++;
            d2[r[i]]++;
        }
        long long ans = 0;
        for(int i = 1; i <= k; i++){
            ans += (k - d1[l[i]] - d2[r[i]] + 1) > 0 ? (k - d1[l[i]] - d2[r[i]] + 1) : 0;
        }
        cout << ans / 2 << endl;
    }
    cin.get();
    cin.get();
    return 0;
}