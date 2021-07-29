#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int Mod = 200907;

LL qmi(LL a, LL b, LL k = 200907){
    LL res = 1;
    while(b){
        if(b & 1) res = (res * a) % k;
        a = (a * a) % k;
        b >>= 1;
    }
    return res % k;
}

LL t, a, b, c, k;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        if(2 * b == a + c){
            int d = (b - a) % Mod;
            LL ans = (a % Mod + ((k - 1) * d) % Mod) % Mod;
            cout << ans << endl;
        }
        else{
            int p = b / a;
            LL r = qmi(p, k - 1);
            LL ans = ((a%Mod) * r) % Mod;
            cout << ans << endl;
        }
    }
    return 0;
}