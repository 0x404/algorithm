#include <cstdio>
#include <iostream>
using namespace std;


int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        int cnt = 0, tmp = n;
        int p = 1;
        while(tmp){
            if(tmp > 0 && tmp < 10) p = tmp;
            cnt++;
            tmp /= 10;
            
        }
        ans += 10 * (p - 1) + ((1+cnt)*cnt)/2;
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}