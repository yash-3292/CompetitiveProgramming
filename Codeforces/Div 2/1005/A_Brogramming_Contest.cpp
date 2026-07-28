#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    if(s[0] == '1') ans++;
    for(int i=1; i<n; i++){
        if(s[i-1] != s[i]) ans++;
    } 
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}