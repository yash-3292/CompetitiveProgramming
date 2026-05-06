#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll water(vector<ll> &arr, ll height){
    ll sum = 0;
    for(ll val : arr){
        if(height > val) sum += height - val;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll low = 1;
        ll high = 1e10;
        ll ans = -1;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll waterSum = water(arr, mid);
            if(waterSum == x){
                ans = mid;
                break;
            } else if(waterSum > x){
                high = mid - 1;
            } else{
                ans = mid;
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}