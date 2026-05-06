#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        ll cnt = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            cnt += (ll)b[i];
            if(cnt > (ll)n) break;
            ll val = (ll)a[n-cnt] * (ll)(i+1);
            ans = max(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}