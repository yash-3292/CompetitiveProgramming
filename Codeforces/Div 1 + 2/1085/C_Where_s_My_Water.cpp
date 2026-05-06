#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, h;
        cin >> n >> h;
        ll ans = n * h;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        if(n == 1){
            ll ans = (h-arr[0]);
            cout << ans << endl;
            continue;
        }
        vector<vector<ll>> mat(n, vector<ll>(n));
        for(ll i=0; i<n; i++){
            mat[i][i] = arr[i];
            for(ll j=i-1; j>=0; j--) mat[i][j] = max(arr[j], mat[i][j+1]);
            for(ll j=i+1; j<n; j++) mat[i][j] = max(arr[j], mat[i][j-1]);
            for(ll j=1; j<n; j++) mat[i][j] += mat[i][j-1];
        }
        ll mini = LLONG_MAX;
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                ll l = i;
                ll r = j-1;
                while(l <= r){
                    ll mid1 = l + (r - l) / 3;
                    ll mid2 = r - (r - l) / 3;
                    ll val1 = mat[i][mid1];
                    val1 += mat[j][n-1] - mat[j][mid1];
                    ll val2 = mat[i][mid2];
                    val2 += mat[j][n-1] - mat[j][mid2];
                    mini = min(mini, val1);
                    mini = min(mini, val2);
                    if(val1 <= val2){
                        r = mid2-1;
                    } else{
                        l = mid1+1;
                    }
                }
            }
        }
        ans -= mini;
        cout << ans << endl;
    }
    return 0;
}