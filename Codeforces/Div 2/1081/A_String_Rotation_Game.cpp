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
        int cnt = 1;
        int flag = 0;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) flag = 1;
            else cnt++;
        }
        if(flag && s[0] != s[n-1]) cnt++;
        cout << cnt << endl; 
    }
    return 0;
}