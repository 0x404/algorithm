/*
 * @author: 0x404
 * @Date: 2021-08-15 19:42:19
 * @LastEditTime: 2021-08-15 19:48:34
 * @Description: 牛牛的Link Power I 
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 100, mod = 1e9 + 7;

using LL = long long;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    LL sum = 0, cnt = 0, ans = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '1')
        {
            ans = (ans + cnt * (i + 1) - sum) % mod;
            sum += i + 1;
            cnt += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
