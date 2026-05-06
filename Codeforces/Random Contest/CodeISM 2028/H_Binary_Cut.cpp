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
        int x = 1;
        int ans = 1;
        for(int i=1; i<n; i++){
            if(s[i-1] == '0' && s[i] == '1'){
                if(x) x--;
                else ans++;
            } else if(s[i-1] == '1' && s[i] == '0'){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}