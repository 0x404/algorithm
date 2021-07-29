#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

const int Mod = 100003;

typedef long long LL;

using namespace std;


LL m, n;

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = (res * a) % Mod;
        a = (a * a) % Mod;
        b >>= 1;
    }
    return res % Mod;
}

int main(){
    cin >> m >> n;
    LL tot = qmi(m, n);
    LL res = (m * qmi(m - 1, n - 1)) % Mod;
    cout << (tot - res + Mod) % Mod << endl;
    return 0;
}