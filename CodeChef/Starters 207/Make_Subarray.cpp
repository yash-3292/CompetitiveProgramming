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
        int l = -1;
        int r = -1;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                l = i;
                break;
            }
        }
        if(l == -1){
            cout << 0 << endl;
            continue;
        }
        for(int i=n-1; i>=0; i--){
            if(s[i] == '1'){
                r = i;
                break;
            }
        }
        int ans = 0;
        for(int i=l; i<=r; i++){
            if(s[i] == '0') ans++;
        }
        cout << ans << endl;
    }
    return 0;
}