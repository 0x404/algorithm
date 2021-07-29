#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n;
vector<int> vec;
int main(){
    cin >> t;
    while(t--){
        vec.clear();
        cin >> n;
        for(int i = 1, x; i <= n; i++){
            cin >> x;
            vec.push_back(x);
        }
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}