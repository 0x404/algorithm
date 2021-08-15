/*
 * @author: 0x404
 * @Date: 2021-08-15 21:37:01
 * @LastEditTime: 2021-08-15 21:41:06
 * @Description: 牛牛的猜球游戏 
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 100;

int pre[N][10], to[10], n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < 10; ++i) pre[0][i] = i;
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        cin >> l >> r;
        for (int j = 0; j < 10; ++j) pre[i][j] = pre[i - 1][j];
        swap(pre[i][l], pre[i][r]);
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        for (int i = 0; i < 10; ++i) to[pre[l - 1][i]] = i;
        for (int i = 0; i < 10; ++i)
            cout << to[pre[r][i]] << " ";
        cout << endl;
    }
    return 0;
}
