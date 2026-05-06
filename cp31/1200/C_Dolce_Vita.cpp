#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        vector<ll> sum(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0; i<n; i++){
            if(i == 0) sum[i] = arr[i];
            else sum[i] = sum[i-1] + arr[i];
        }
        ll cnt = 0;
        for(int i=0; i<n; i++){
            if(sum[i] > x) break;
            cnt += (x - sum[i]) / (ll)(i + 1) + (ll)1;
        }
        cout << cnt << endl;
    }
    return 0;
}