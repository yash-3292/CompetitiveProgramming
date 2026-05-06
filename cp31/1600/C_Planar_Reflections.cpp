#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = (ll)(1e9+7);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k ==1){
            cout << 1 << endl;
            continue;
        } else if(k == 2){
            cout << 1+n << endl;
            continue;
        }
        vector<ll> arr(n, 1);
        ll ans = (ll)(1+n);
        for(int i=0; i<k-2; i++){
            vector<ll> pref(n, 0);
            if(i&1){
                for(int j=1; j<n; j++){
                    pref[j] = (pref[j-1]+arr[j-1])%mod;
                    ans = (ans+pref[j])%mod;
                }
            } else{
                for(int j=n-2; j>=0; j--){
                    pref[j] = (pref[j+1]+arr[j+1])%mod;
                    ans = (ans+pref[j])%mod;
                }
            }
            arr = pref;
        }
        cout << ans << endl;
    }
    return 0;
}