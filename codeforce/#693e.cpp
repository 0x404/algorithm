#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

const int N = 2e5 + 10;

struct Node{
    int id, h, w;

    bool operator < (const Node& rhs){
        if(h == rhs.h) return w < rhs.w;
        return h < rhs.h;
    }
};

Node a[N];
int t, n;
int mn1[N], mn2[N], pos1[N], pos2[N], ans[N];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) ans[i] = -1;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &a[i].h, &a[i].w),
            a[i].id = i;
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; i++)
            mn1[i] = a[i].w,
            pos1[i] = i;
        for()
    }
}
