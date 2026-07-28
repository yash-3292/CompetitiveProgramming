#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 1;
    int ans = 0;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            cnt++;
        } else{
            ans += cnt/3;
            cnt = 1;
        }
    }
    ans += cnt/3;
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