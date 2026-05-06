#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> arr(n); 
        ll ans = 0;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<63; i++){
            ll val = (ll)1 << i;
            for(int j=0; j<n; j++){
                if((arr[j] & val) == 0){
                    if(k >= val){
                        arr[j] += val;
                        k -= val;
                        ans++;
                    }
                } else{
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}