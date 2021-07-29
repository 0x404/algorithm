#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

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
    cin >> n;
    if(n <= 2) cout << 1 << endl;
    else cout << 2 << endl;
    for(int i = 2; i <= n + 1; i++)
        if(!st[i]) cout << 1 << " ";
        else cout << 2 << " ";
    return 0;
}