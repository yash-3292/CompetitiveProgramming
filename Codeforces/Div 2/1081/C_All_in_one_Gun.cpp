#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, ll h ,vector<ll>& arr){
    int n = arr.size();
    ll sum = 0;
    ll mini = 1e18;
    ll maxi = -1e18;
    for(int i=0; i<mid; i++){
        sum += arr[i];
        mini = min(mini, arr[i]);
    } 
    for(int i=mid; i<n; i++) maxi = max(maxi, arr[i]);
    sum = sum + max((maxi - mini), 0LL);
    return sum >= h;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll h, k;
        cin >> n >> h >> k;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];
        ll cnt = h / sum;
        h = h % sum;
        if(h == 0){
            cnt--;
            ll ans = k*cnt + (ll)n*(cnt+1);
            cout << ans << endl;
            continue;
        }
        ll ans = cnt*k + (ll)n*(cnt);
        int l = 1;
        int r = n;
        int ind = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(mid, h, arr)){
                ind = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        ans += (ll)ind;
        cout << ans << endl;
    }
    return 0;
}