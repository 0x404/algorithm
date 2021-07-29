#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

int v1[N], v2[N], l1, l2;
int t, n, m;
int a[N], b[N];
long long sum1[N], sum2[N];


bool cmp(int a, int b){return a > b;}


int main(){
    cin >> t;
    while(t--){
        memset(sum1, 0, sizeof sum1);
        memset(sum2, 0, sizeof sum2);
        l1 = 0;
        l2 = 0;
        long long sum = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i];
        for(int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        if(sum < m){
            cout << -1 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++)
            if(b[i] == 1) v1[++l1] = a[i];
            else v2[++l2] = a[i];
        sort(v1 + 1, v1 + l1 + 1, cmp);
        sort(v2 + 1, v2 + l2 + 1, cmp);
        for(int i = 1; i <= l1; i++)
            sum1[i] = sum1[i-1] + v1[i];
        for(int i = 1; i <= l2; i++)
            sum2[i] = sum2[i-1] + v2[i];
        int ans = 99999999;
        for(int i = 0; i <= l1; i++){
            if(sum2[l2] < m - sum1[i]) continue;
            int tmp = i;
            if(m - sum1[i] > 0)
                tmp += 2 * (lower_bound(sum2 + 1, sum2 + 1 + l2, m - sum1[i]) - sum2);
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    cin.get();
    cin.get();
    return 0;
}   