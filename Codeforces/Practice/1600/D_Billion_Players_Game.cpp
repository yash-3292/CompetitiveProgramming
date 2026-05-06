#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = n-1;
        ll ans = 0;
        while(i < j){
            if(arr[i] < l && arr[j] < l) break;
            if(arr[i] > r && arr[j] > r) break;
            ans += (ll)(arr[j]-arr[i]);
            i++; j--;
        }
        for(int k=i; k<=j; k++){
            if(arr[k] < l){
                ans += (ll)(l-arr[k]);
            } else if(arr[k] > r){
                ans += (ll)(arr[k]-r);
            }
        }
        cout << ans << endl;
    }
    return 0;
}