#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        ll zero = 0;
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            ll val = arr[i] * (1 << zero);
            if(val <= c){
                zero++;
            } else{
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}