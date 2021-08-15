/*
 * @author: 0x404
 * @Date: 2021-08-15 19:34:46
 * @LastEditTime: 2021-08-15 19:38:45
 * @Description: 智乃酱的区间乘积 
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


using LL = long long;

const LL mod = 1e9 + 7, N = 1e5 + 10;

LL a[N], sum[N], n, m;


LL qmi(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sum[0] = 1;
    for (int i = 1; i <= n; ++i) sum[i] = (sum[i - 1] * a[i]) % mod;
    while (m--)
    {
        LL l, r;
        cin >> l >> r;
        LL inv = qmi(sum[l - 1], mod - 2);
        cout << (inv * sum[r]) % mod << endl;
    }
    return 0;
}
