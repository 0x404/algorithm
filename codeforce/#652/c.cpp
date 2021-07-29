#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

typedef long long LL;

const int N = 2e5 + 100;

int a[N], b[N], c[N], t, n, m, sz;
map<int, int> cnt;

int main(){
    // freopen("ans.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        LL ans = 0;
        int l = 1, r = n;
        for(int i = 1; i <= m; i++){
            if(b[i] == 1)
                ans += 2 * a[r--];
        }
        for(int i = m; i >= 1; i--){
            if(b[i] == 1) continue;
            ans += a[r] + a[l];
            l += b[i] - 1;
            r -= 1;
        }
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}