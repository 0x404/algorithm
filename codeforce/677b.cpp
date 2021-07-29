#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100
using namespace std;


int t, pos[MAXN], n, len;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        len = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(len == 0 || x == 0) pos[++len] = x;
            if(x == 1 && pos[len] == 0) pos[++len] = 1;
        }
        vector<int> a;
        for(int i = 1; i <= len; i++)
            if(pos[i] == 1) a.push_back(i);
        sort(a.begin(), a.end());
        int midx = a[a.size() / 2];
        int mid = a.size() / 2;
        int ls = midx;
        int ans = 0;
        for(int i = mid - 1; i >= 0; i--){
            ans += ls - a[i] - 1;
            ls = a[i];
        }
        ls = midx;
        for(int i = mid + 1; i < a.size(); i++){
            ans += a[i] - ls - 1;
            ls = a[i];
        }
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}