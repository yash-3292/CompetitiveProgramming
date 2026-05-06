#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 0){
            cout << "YES" << endl;
            continue;
        }
        int temp = n;
        int flag = 1;
        int cnt = 0;
        string s = "";
        for(int i=0; i<32; i++){
            if(temp == 0) break;
            if(temp&(1<<i)){
                s += '1';
                temp = (temp^(1<<i));
                flag = 0;
            } else{
                s += '0';
                if(flag) cnt++;
            }
        }
        for(int i=0; i<cnt; i++) s += '0';
        string t = s;
        reverse(t.begin(), t.end());
        if(t != s){
            cout << "NO" << endl;
            continue;
        } 
        int sz = s.size();
        if(sz&1){
            if(s[sz/2] == '1'){
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}