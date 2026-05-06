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
        int mini = 0;
        for(int i=0; i<n; i++) if(s[i] == '1') mini++;
        for(int i=1; i<n-1; i++){
            if(s[i-1] == '1' && s[i+1] == '1') s[i] = '1';
        }
        int maxi = 0;
        for(int i=0; i<n; i++) if(s[i] == '1') maxi++;
        for(int i=1; i<n-1; i++){
            if(s[i-1] == '1' && s[i+1] == '1') s[i] = '0';
        }
        int val = 0;
        for(int i=0; i<n; i++) if(s[i] == '1') val++;
        mini = min(mini, val);
        cout << mini << " " << maxi << endl;
    }
    return 0;
}