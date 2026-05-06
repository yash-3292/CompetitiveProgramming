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
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ans += 3;
                if(i == 0) ans--;
                if(i == n-1) ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}