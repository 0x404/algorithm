#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, k;

string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        int cq = 0, c1 = 0, c0 = 0;
        int l = 0, r = k - 1;
        for(int i = l; i <= r; i++){
            if(s[i] == '0') c0++;
            if(s[i] == '1') c1++;
            if(s[i] == '?') cq++;
        }        
        if(c0 > c1 && c1 + cq < c0){
            cout << "NO" << endl;
            continue;
        }
        if(c1 > c0 && c0 + cq < c1){
            cout << "NO" << endl;
            continue;
        }
        bool flag = true;
        while(r + 1 < n){
            char lef = s[l];
            char rig = s[r + 1];
            if((lef == '1' && rig == '0') || (lef == '0' && rig == '1')){
                cout << "NO" << endl;
                flag = false;
                break;
            }
            if(lef == '1' && rig == '?') s[r + 1] = '1';
            if(lef == '0' && rig == '?') s[r + 1] = '0';
            if(lef == '?' && rig == '1') s[l] = '1';
            if(lef == '?' && rig == '0') s[l] = '0';
            l++;
            r++; 
        }
        if(!flag) continue;
        cq = 0, c1 = 0, c0 = 0;
        l = 0, r = k - 1;
        for(int i = l; i <= r; i++){
            if(s[i] == '0') c0++;
            if(s[i] == '1') c1++;
            if(s[i] == '?') cq++;
        }
        if(c0 > c1 && c1 + cq < c0){
            cout << "NO" << endl;
            continue;
        }
        if(c1 > c0 && c0 + cq < c1){
            cout << "NO" << endl;
            continue;
        }
        while(r + 1 < n){
            if(c0 > c1 && c1 + cq < c0){
                cout << "NO" << endl;
                flag = false;
                break;
            }
            if(c1 > c0 && c0 + cq < c1){
                cout << "NO" << endl;
                flag = false;
                break;
            }
            if(s[r + 1] == '0') c0++;
            if(s[r + 1] == '1') c1++;
            if(s[r + 1] == '?') cq++;
            if(s[l] == '0') c0--;
            if(s[l] == '1') c1--;
            if(s[l] == '?') cq--;
            l++;
            r++;
        }
        if(flag)
            cout << "YES" << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}