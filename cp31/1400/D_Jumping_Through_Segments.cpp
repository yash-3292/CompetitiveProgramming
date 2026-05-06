#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define f first
#define s second

bool isPossible(vector<pair<ll,ll>>& arr, ll k){
    int n = arr.size();
    pair<ll,ll> curr = {-k, k};
    for(int i=0; i<n; i++){
        if(curr.s < arr[i].f || curr.f > arr[i].s){
            return false;
        }
        curr.s = min(curr.s, arr[i].s) + k;
        curr.f = max(curr.f, arr[i].f) - k;

    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].f >> arr[i].s;
        }
        if(n == 1){
            cout << arr[0].f << endl;
            continue;
        }
        ll low = 0;
        ll high = 2e9;
        ll ans = high;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(isPossible(arr, mid)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        cout << ans << endl;
    }
}