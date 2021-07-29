#include <cstdio>
#include <iostream>
#define MAXN 300500
using namespace std;

int t, n, a[MAXN];

int main(){
    cin >> t;
    int cheak;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int maxx = 0;
        for(int i = 1; i <= n; i++) maxx = max(maxx, a[i]);
        bool f = false;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == maxx && ((i + 1 <= n && a[i+1] < maxx) || (i - 1 >= 1 && a[i-1] < maxx))){
                f = true;
                ans = i;
                break;
            }
        }
        if(f) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}