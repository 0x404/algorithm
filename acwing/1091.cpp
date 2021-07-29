#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1050;

int mat[N][N], n, m, k;
int maxd[N][N], mind[N][N], maxc[N][N], minc[N][N];

void colMax(int col){
    deque<int> q;
    for(int i = 1; i < k; i++){
        while(!q.empty() && mat[col][i] >= mat[col][q.back()]) q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i <= m; i++){
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        while(!q.empty() && mat[col][i] >= mat[col][q.back()]) q.pop_back();
        q.push_back(i);
        maxd[col][i] = mat[col][q.front()];
    }
}

void colMin(int col){
    deque<int> q;
    for(int i = 1; i < k; i++){
        while(!q.empty() && mat[col][i] <= mat[col][q.back()]) q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i <= m; i++){
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        while(!q.empty() && mat[col][i] <= mat[col][q.back()]) q.pop_back();
        q.push_back(i);
        mind[col][i] = mat[col][q.front()];
    }
}

void rowMax(int row){
    deque<int> q;
    for(int i = 1; i < k; i++){
        while(!q.empty() && maxd[i][row] >= maxd[q.back()][row]) q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i <= n; i++){
        while(!q.empty() && maxd[i][row] >= maxd[q.back()][row]) q.pop_back();
        q.push_back(i);
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        maxc[i][row] = maxd[q.front()][row];
    }
}

void rowMin(int row){
    deque<int> q;
    for(int i = 1; i < k; i++){
        while(!q.empty() && mind[i][row] <= mind[q.back()][row]) q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i <= n; i++){
        while(!q.empty() && q.front() <= i - k) q.pop_front();
        while(!q.empty() && mind[i][row] <= mind[q.back()][row]) q.pop_back();
        q.push_back(i);
        minc[i][row] = mind[q.front()][row];
    }
}


int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &mat[i][j]);
    for(int i = 1; i <= n; i++)
        colMax(i), colMin(i);
    for(int i = k; i <= m; i++)
        rowMax(i), rowMin(i);
    int ans = 1000000005;
    for(int i = k; i <= n; i++)
        for(int j = k; j <= m; j++)
            ans = min(ans, maxc[i][j] - minc[i][j]);
    cout << ans << endl;
    // cin.get();
    // cin.get();
    return 0;
}