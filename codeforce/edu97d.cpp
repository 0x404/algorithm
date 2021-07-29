#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


const int N = 200500;

int t, n, a[N];
int lsL = 0, nowL = 1, lsP = 0;
vector<int> depV[N];

int main(){
    cin >> t;
    depV[0].push_back(1);
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        lsL = 0, nowL = 1, lsP = 0;   
        depV[1].push_back(a[2]);
        for(int i = 3; i <= n; i++){
            // cout << a[i] << endl;
            if(a[i] > a[i-1]){
                depV[nowL].push_back(a[i]);
            }
            else{
                if(lsP + 1 >= depV[lsL].size()){
                    lsL = nowL;
                    nowL = nowL + 1;
                    depV[nowL].push_back(a[i]);
                    lsP = 0;
                }
                else{
                    lsP++;
                    depV[nowL].push_back(a[i]);
                }
            }
        }
        cout << nowL << endl;    
        // for(int i = 0; i <= nowL; i++, cout<<endl)
        //     for(auto x : depV[i]) cout << x << " ";
        for(int i = 1; i <= nowL + 1; i++) depV[i].clear();
    }
    // cin.get();
    // cin.get();
    return 0;
}