#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

void fastIO() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL); 
}

int main(){
    fastIO();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll ans = 0;
        vector<ll> freq(60, 0);
        for(int i=0; i<n; i++){
            for(int x=0; x<60; x++){
                if((arr[i] & (1LL<<x))) freq[x]++;
            }
        }
        for(int i=0; i<n; i++){
            ll a = 0;
            ll o = 0;
            for(int x=0; x<60; x++){
                if((arr[i] & (1LL<<x))){
                    // cout << x << endl;
                    a = (a + (freq[x] * ((1LL<<x)%mod))%mod)%mod;
                    o = (o + ((ll)n * ((1LL<<x)%mod))%mod)%mod;
                } else{
                    o = (o + (freq[x] * ((1LL<<x)%mod))%mod)%mod;
                }
            }
            // for(int j=0; j<n; j++) a = (a + (arr[i] & arr[j])%mod)%mod;
            // for(int j=0; j<n; j++) o = (o + (arr[i] | arr[j])%mod)%mod;
            ll val = (o * a)%mod;
            // cout << o << " " << a << endl;
            ans = (ans + val)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}