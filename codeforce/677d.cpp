#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 5050
using namespace std;

int t, n, a[MAXN], f[MAXN];
int main(){
    cin >> t;
    while(t--){
        bool f = true;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i++) if(a[i] != a[i-1]) f = false;
        if(f){
            cout << "NO" << endl;
            continue;
        }
        // asdadw
        cout << "YES" << endl;
        int mark = a[1];
        int pos = -1;
        for(int i = 2; i <= n; i++){
            if(a[i] != mark){
                cout << 1 << " " << i << endl;
                pos = i;
            }
        }
        for(int i = 2; i <= n; i++){
            if(a[i] == mark){
                cout << pos << " " << i << endl;
            }
        }
    }
    // cin.get();
    // cin.get();
    return 0;
}