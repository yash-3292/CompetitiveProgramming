#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), c(n);
        ll sum = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> c[i];
        for(int i=0; i<n; i++){
            sum += (ll)c[i];
        }
        vector<ll> dp(n);
        for(int i=0; i<n; i++) dp[i] = (ll)c[i];
        ll ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(a[j] <= a[i]){
                    dp[i] = max(dp[i], (ll)c[i]+dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        sum -= ans;
        cout << sum << endl;
    }
    return 0;
}