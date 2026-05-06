#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        ll ans = 0;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                ll xori = arr[i]^arr[i-1];
                ll val = 1;
                while(val <= xori) val *= 2;
                val /= 2;
                ans = max(val, ans);
                while(val != 0){
                    arr[i] = arr[i] | val;
                    if(arr[i] >= arr[i-1]) break;
                    val /= 2;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}