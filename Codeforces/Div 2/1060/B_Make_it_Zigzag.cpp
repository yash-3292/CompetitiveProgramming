#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
            if(i%2 == 1){
                arr[i] = maxi;
            }
        }
        ll ans = 0;
        for(int i=0; i<n; i+=2){
            int val;
            if(i == 0) val = arr[1];
            else if(i == n-1) val = arr[i-1];
            else val = min(arr[i-1], arr[i+1]);
            if(arr[i] >= val){
                ans += (ll)(arr[i]-(val-1));
            } 
        }
        cout << ans << endl;
    }
    return 0;
}