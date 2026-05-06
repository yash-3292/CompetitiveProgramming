#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int cnt = 0;
        int diffBrac = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == 0){
                diffBrac++;
            }
        }
        if(diffBrac == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}