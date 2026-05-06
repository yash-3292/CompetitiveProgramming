#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            int rem = arr[i]%k;
            if(rem){
                mpp[k-rem]++;
            }
        } 
        if(mpp.empty()){
            cout << 0 << endl;
            continue;
        }
        int maxcnt = 0;
        int maxi = 0;
        for(auto it : mpp){
            if(it.second >= maxcnt){
                maxcnt = it.second;
                maxi = it.first;
            }
        }
        ll ans = (ll)k*(ll)(maxcnt-1) + (ll)maxi + 1;
        cout << ans << endl;
    }
    return 0;
}