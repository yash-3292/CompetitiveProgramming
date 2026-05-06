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
        int permi = 0;
        int flag = 1;
        for(int i=0; i<n; i++){
            if(s[i] == '1') permi = 1;
            else{
                if(permi){
                    permi = 0;
                    continue;
                }
                if(i == n-1){
                    flag = 0;
                    break;
                }
                if(s[i+1] == '1'){
                    i++;
                } else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}