/*
 * @author: 0x404
 * @Date: 2021-08-15 22:52:23
 * @LastEditTime: 2021-08-15 23:15:43
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 100;

LL n, m, l;
LL a[N], b[N], c[N];


LL find(LL x, LL w[], LL len)
{
    int l = 1, r = len;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (w[mid] <= x) l = mid + 1;
        else r = mid - 1;
    }
    return max(w[r], w[l]);
}


int main()
{
    cout << pow(2, 17) << endl;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= l; ++i) cin >> c[i];
    
    LL ans = 1e15;

    for (int i = 1; i <= n; ++i)
    {
        int index_b = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        int index_c = lower_bound(c + 1, c + 1 + l, a[i]) - c;
        LL x = b[index_b], y = c[index_c];
        if (index_b <= m && index_c <= l)
            ans = min(ans, abs(a[i] - x) + abs(a[i] - y) + abs(x - y));
    
    }
    for (int i = 1; i <= m; ++i)
    {
        int index_a = lower_bound(a + 1, a + 1 + n, b[i]) - a;
        int index_c = lower_bound(c + 1, c + 1 + l, b[i]) - c;
        LL x = a[index_a];
        LL y = c[index_c];
        if (index_a <= n &&  index_c <= l)
            ans = min(ans, abs(b[i] - x) + abs(b[i] - y) + abs(x - y));
    }
    for (int i = 1; i <= l; ++i)
    {
        int index_a = lower_bound(a + 1, a + 1 + n, c[i]) - a;
        int index_b = lower_bound(b + 1, b + 1 + m, c[i]) - b;
        LL x = a[index_a];
        LL y = b[index_b];
        if (index_a <= n && index_b <= m)
            ans = min(ans, abs(c[i] - x) + abs(c[i] - y) + abs(x - y));
    }
    cout << ans << endl;
    return 0;
}
