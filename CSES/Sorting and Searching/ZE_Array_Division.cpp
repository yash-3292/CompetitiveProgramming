#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int totalArr(ll val, vector<int>& arr){
    int n = arr.size();
    int cnt = 1;
    ll sum = 0;
    for(int i=0; i<n; i++){
        if(sum + (ll)arr[i] > val){
            cnt++;
            sum = 0;
        }
        sum += (ll)arr[i];
    }
    return cnt;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int maxi = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    } 
    ll low = maxi;
    ll hi = 1e18;
    ll ans = -1;
    while(low <= hi){
        ll mid = low + (hi-low)/2;
        int num = totalArr(mid, arr);
        if(num <= k){
            ans = mid;
            hi = mid-1;
        } else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}