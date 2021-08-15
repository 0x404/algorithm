/*
 * @author: 0x404
 * @Date: 2021-08-15 20:44:43
 * @LastEditTime: 2021-08-15 23:36:14
 * @Description: 小w的糖果 
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 100, mod = 1e9 + 7;

long long a[N], b[N], c[N], n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        cin >> n >> m;
        while (m--)
        {
            int type, pos;
            cin >> type >> pos;
            if (type == 1) a[pos]++;
            if (type == 2) b[pos]++;
            if (type == 3) c[pos]++, c[pos + 1]++;
        }
        int now = 0;
        for (int i = 1; i <= n; ++i)
        {
            now = (c[i] + now) % mod;
            b[i] = (b[i] + now) % mod;
        }
        now = 0;
        for (int i = 1; i <= n; ++i)
        {
            now = (b[i] + now) % mod;
            a[i] = (a[i] + now) % mod;
        }
        now = 0;
        for (int i = 1; i <= n; ++i)
        {
            now = (a[i] + now) % mod;
            cout << now << " ";
        }
        cout << endl;
    }
    return 0;
}
