#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt, n;
bool st[N];

void init(){
    for(int i = 2; i < N; i++){
        if(!st[i]) primes[++cnt] = i;
        for(int j = 1; j <= cnt && primes[j] * i < N; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}


int main(){
    init();
    while(cin >> n, n){
        for(int i = 2; i <= cnt; i++){
            int x = primes[i];
            if(!st[n - x]){
                printf("%d = %d + %d\n", n, x, n - x);
                break;
            }
        }
    }
    cin.get();
    cin.get();
    return 0;
}