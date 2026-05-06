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
        int i;
        if(n&1){
            if(s[0] == 'b'){
                cout << "NO" << endl;
                continue;
            }
            i = 1;
        } else{
            i = 0;
        }
        int flag = 1;
        for(; i<n; i+=2){
            if(s[i] != '?' && s[i] == s[i+1]){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}