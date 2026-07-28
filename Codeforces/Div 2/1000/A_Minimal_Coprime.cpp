#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int l, r;
    cin >> l >> r;
    int ans;
    if(r > l){
        ans = r-l;
    } else{
        if(l == 1) ans = 1;
        else ans = 0;
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