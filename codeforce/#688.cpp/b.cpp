#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


const int N = 1e5 + 10;

typedef long long LL;

int a[N], n, t;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        LL sum = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > 0) sum += a[i];
            else if(a[i] < 0 && sum > 0){
                if(sum + a[i] >= 0){
                    sum -= -a[i];
                    a[i] = 0;
                }
                else{
                    a[i] += sum;
                    sum = 0;
                }
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] < 0) ans += -a[i];
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}