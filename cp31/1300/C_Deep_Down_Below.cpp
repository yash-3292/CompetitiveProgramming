#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> arr(n);
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            int maxi = 0;
            for(int j=0; j<k; j++){
                int a;
                cin >> a;
                maxi = max(maxi, a+1-j);
            }
            arr[i].first = (ll)maxi;
            arr[i].second = (ll)k;
        }
        sort(arr.begin(), arr.end());
        vector<ll> sum(n);
        sum[0] = (ll)0;
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1] + arr[i-1].second;
        }
        ll ans = 0;
        for(int i=0; i<n; i++){
            ll val = arr[i].first - sum[i];
            ans = max(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}