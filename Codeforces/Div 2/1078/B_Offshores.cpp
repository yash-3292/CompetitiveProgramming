#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        for(int i=0; i<n; i++) sum += (ll)(arr[i]/x)*y;
        ll ans = 0;
        for(int i=0; i<n; i++){
            ll val = sum - (ll)(arr[i]/x)*y + (ll)arr[i];
            ans = max(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}