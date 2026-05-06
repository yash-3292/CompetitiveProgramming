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
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++;
            else cnt--;
            if(cnt > 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}