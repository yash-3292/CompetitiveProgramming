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
        int ans = count(s.begin(), s.end(), '1');
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                if(i != 0 && s[i-1] == '1') continue;
                if(i != n-1 && s[i+1] == '1') continue;
                cnt++;
            } else{
                if(cnt) ans += (cnt-1)/3 + 1;
                cnt = 0;
            }
        }
        if(cnt) ans += (cnt-1)/3 + 1;
        cout << ans << endl;
    }
    return 0;
}