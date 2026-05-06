#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll a, b;
        cin >> n >> a >> b;
        vector<ll> arr(n+1);
        arr[0] = 0;
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<ll> preSum(n+1);
        preSum[0] = arr[0];
        for(int i=1; i<=n; i++) preSum[i] = preSum[i-1] + arr[i];
        ll ans = LLONG_MAX;
        for(int i=0; i<=n; i++){
            ll val = (a+b)*arr[i];
            ll temp = preSum[n] - preSum[i] - (n-i)*arr[i];
            val += b*temp;
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}