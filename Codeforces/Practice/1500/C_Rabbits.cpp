#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int flag = 1;
        int safe = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                if(i == 0){
                    safe = 1;
                    cnt++;
                    continue;
                } 
                if(s[i-1] == '0'){
                    safe = 1;
                } else{
                    cnt++;
                }
            } else{
                if(i == 0) continue;
                if(s[i-1] == '1'){
                    if(safe){
                        safe = 0;
                        cnt = 0;
                        continue;
                    }
                    if(cnt&1){
                        flag = 0;
                        break;
                    }
                    safe = 0;
                    cnt = 0;
                }
            }
        }
        if(s[n-1] == '1'){
            if(safe){
                safe = 0;
                cnt = 0;
            }
            if(cnt&1){
                flag = 0;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}