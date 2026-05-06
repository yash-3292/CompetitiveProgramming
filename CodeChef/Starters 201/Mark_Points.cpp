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
        int cnt = 0;
        int flag = 1;
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++;
            else{
                if(cnt < 3 && cnt != 0) flag = 0;
                cnt = 0;
            } 
        }
        if(cnt < 3 && cnt != 0) flag = 0;
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}