#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int primes[N], cnt, n;
int factor[N];
bool st[N];

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[++cnt] = i;
        for(int j = 1; j <= cnt && primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res *= a;
        a = a * a;
        b >>= 1; 
    }
    return res;
}


int main(){
    cin >> n;
    init(n);
    for(int i = 1; i <= cnt; i++){
        LL p = primes[i];
        if(p > n) continue;
        while(p <= n){
            factor[primes[i]] += n / p;
            p = p * primes[i];
        }
    }
    for(int i = 2; i <= n; i++)
        if(factor[i] != 0) cout << i << " " << factor[i] << endl;
    
    // cin.get();
    // cin.get();
    return 0;
}