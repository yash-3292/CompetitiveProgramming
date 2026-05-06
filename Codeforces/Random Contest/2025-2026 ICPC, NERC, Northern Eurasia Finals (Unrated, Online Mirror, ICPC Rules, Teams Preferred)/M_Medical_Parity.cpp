#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        string t;
        cin >> s >> t;
        int n = s.size();
        vector<int> x(n+1, 0);
        vector<int> y(n+1, 0);
        for(int i=0; i<n; i++) if(s[i] == '1') x[i+1] = 1;
        for(int i=0; i<n; i++) if(t[i] == '1') y[i+1] = 1;
        int ans = 0;
        for(int i=1; i<=n; i++){
            int val = (y[i-1]^y[i]);
            if(val == x[i]){
                continue;
            }
            if(i == n){
                x[i] = val;
                ans++;
                continue;
            } 
            int val1 = (y[i]^y[i+1]);
            if(val1 != x[i+1]){
                ans++;
                y[i] = (!y[i]);
            } else{
                x[i] = val;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}