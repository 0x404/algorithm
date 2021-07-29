#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int t, len;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> len;
        cin >> s;
        int l = -1, r = -1;
        int p = 0;
        while(p + 1 < len){
            if(s[p] == '1' && s[p + 1] == '0'){
                l = p;
                break;
            }
            p++;
        }
        if(l == -1){
            cout << s << endl;
            continue;
        }
        p = len - 1;
        while(p - 1 >= 0){
            if(s[p] == '0' && s[p - 1] == '1'){
                r = p;
                break;
            }
            p--;
        }
        while(l - 1 >= 0 && s[l - 1] == '1') l--;
        while(r + 1 < len && s[r + 1] == '0') r++;
        string ans = "";
        for(int i = 0; i < l; i++) ans += s[i];
        ans += '0';
        for(int i = r + 1; i < len; i++) ans += s[i];
        cout << ans << endl;
    }
    // cin.get();
    // cin.get();
    return 0;
}