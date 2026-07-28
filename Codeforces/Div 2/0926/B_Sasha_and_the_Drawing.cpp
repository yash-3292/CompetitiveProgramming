#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    int ans;
    if(k <= 4*n-4){
        ans = k/2;
        if(k&1) ans++;
    } else{
        ans = 2*n - 2 + (k - (4*n-4));
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