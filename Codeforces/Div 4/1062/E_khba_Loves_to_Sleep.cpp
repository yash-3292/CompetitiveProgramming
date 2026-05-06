#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll l, ll r){
    return (l <= r) ? r-l+1 : 0;
}

ll f(ll mid, vector<int>& arr, int x){
    int n = arr.size();
    ll ans = 0;
    ans += calc(0, arr[0]-mid);
    ans += calc(arr[n-1]+mid, x);
    for(int i=1; i<n; i++){
        ans += calc(arr[i-1]+mid, arr[i]-mid);
    }
    return ans;
}

void iter(int l, int r, int k, int& cnt){
    for(int i=l; i<=r; i++){
        if(k == cnt) return;
        cnt++;
        cout << i << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        ll l = 0;
        ll r = 1e9;
        ll ans = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            ll val = f(mid, arr, x);
            if(val >= (ll)k){
                ans = mid;
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        if(ans == 0){
            for(int i=0; i<k; i++) cout << i << " ";
            cout << endl;
            continue;
        }
        int cnt = 0;
        iter(0, arr[0]-ans, k, cnt);
        iter(arr[n-1]+ans, x, k, cnt);
        for(int i=1; i<n; i++){
            iter(arr[i-1]+ans, arr[i]-ans, k, cnt);
        }
        cout << endl;
    }
    return 0;
}