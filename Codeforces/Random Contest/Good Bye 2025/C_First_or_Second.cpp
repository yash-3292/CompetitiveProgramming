#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<ll> preSum(n), sufSum(n);
        preSum[0] = 0;
        preSum[1] = arr[0];
        for(int i=2; i<n; i++){
            preSum[i] = preSum[i-1] + abs(arr[i-1]);
        }
        sufSum[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            sufSum[i] = sufSum[i+1] - arr[i+1];
        }
        ll ans = LLONG_MIN;
        for(int i=0; i<n; i++){
            ll val;
            if(i == 0) val = sufSum[i];
            else if(i == n-1) val = preSum[i];
            else val = preSum[i] + sufSum[i];
            ans = max(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}