#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
        map<int,int> mpp1;
        map<int,int> mpp2;
        for(int i=0; i<n; i++){
            mpp1[arr[i].first]++;
            mpp2[arr[i].second]++;
        }
        ll val = 0;
        for(auto it : arr){
            val += (ll)(mpp1[it.first] - 1) * (ll)(mpp2[it.second] - 1); 
        }
        ll ans = ((ll)(n) * (ll)(n-1) * (ll)(n-2))/6;
        ans = ans - val;
        cout << ans << endl;  
    }
    return 0;
}