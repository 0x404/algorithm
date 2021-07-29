#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

long long t, l, r;

int main(){
    cin >> t;
    while(t--){
        cin >> l >> r;
        long long p = l * 2 / 3;
        long long mod1 = p > 0 ? l % p : -1;
        if(mod1 != -1 && r - l + 1 <= (p - mod1)){
            cout << "YES" << endl;
            continue;
        } 
        p = l * 2;
        if(r - l + 1 <= l){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
   return 0;
}