#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(vector<pair<ll,ll>>& arr, ll mid, int n){
    ll rem = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i].first - arr[i].second > mid) return false;
        if(arr[i].first > mid){
            rem += 2*(arr[i].first - mid);
            continue;
        }
        if(arr[i].first < mid){
            rem -= (ll)floor(double(mid-arr[i].first)/2.0) * (ll)2;
        }
    }
    if(rem <= 0) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i].first;
        for(int i=0; i<n; i++) cin >> arr[i].second;
        for(int i=0; i<n; i++){
            arr[i].first = arr[i].first + arr[i].second;
        }
        sort(arr.begin(), arr.end());
        ll low = 0;
        ll high = arr[n-1].first;
        ll ans = high;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(isPossible(arr, mid, n)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}