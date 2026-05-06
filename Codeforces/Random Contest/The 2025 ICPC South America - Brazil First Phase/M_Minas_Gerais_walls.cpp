#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(ll mid, ll k, vector<ll>& arr){
    int n = arr.size();
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(mid > arr[i]){
            if(mid-arr[i] > k) return false;
            temp.push_back(i);
        }
    }
    int m = temp.size();
    if(m == 0) return true;
    for(int i=0; i<m; i++){
        if(temp[m-1]-temp[i]+(mid-arr[temp[i]]) > k) return false;
    }
    return true;
}

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll mini = 1e9;
    for(int i=0; i<n; i++) mini = min(mini, arr[i]);
    ll l = mini;
    ll r = 2e9;
    ll ans = mini;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(isValid(mid, k, arr)){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}