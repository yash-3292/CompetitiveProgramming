#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string s, t;
    cin >> s;
    cin >> t;
    int ans = s.size() + t.size();
    for(int i=0; i<min(s.size(), t.size()); i++){
        if(s[i] == t[i]) ans--;
        else break;
    }
    if(ans < s.size()+t.size()){
        ans++;
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