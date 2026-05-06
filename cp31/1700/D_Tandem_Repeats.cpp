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
        int ans = 0;
        for(int l=1; l<=n/2; l++){
            int cnt = 0;
            for(int i=l; i<n; i++){
                if(s[i] == '?' || s[i-l] == '?' || s[i] == s[i-l]){
                    cnt++;
                } else{
                    cnt = 0;
                }
                if(cnt >= l) ans = 2*l;
            }
        }
        cout << ans << endl;
    }
    return 0;
}