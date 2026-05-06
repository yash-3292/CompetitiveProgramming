#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int val = arr[0];
        for(int i=0; i<n; i++) val &= arr[i];
        ll fact = 1;
        for(int i=1; i<=n-2; i++){
            fact *= (ll)i;
            fact = fact%mod;
        }
        int cnt = 0;
        for(int i=0; i<n; i++) if(arr[i] == val) cnt++;
        ll ans = (ll)cnt*(ll)(cnt-1);
        ans = ans%mod;
        ans *= fact;
        ans = ans%mod;
        cout << ans << endl;
    }
    return 0;
}