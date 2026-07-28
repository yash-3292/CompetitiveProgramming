#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    ll ans = 0;
    for(int i=0; i<n; i++) ans += (ll)abs(a[i]-b[i]);
    for(int i=0; i<n; i++) if(a[i] > b[i]) swap(a[i], b[i]);
    sort(b.begin(), b.end());
    ll maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, (ll)2*(ll)(a[i]-b[0]));
    }
    ans += maxi;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}