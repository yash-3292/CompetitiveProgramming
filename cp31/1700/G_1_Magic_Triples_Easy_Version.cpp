#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x]++;
        } 
        ll ans = 0;
        for(auto it : mpp){
            ll val = it.second;
            ans += val * (val-1) * (val-2);
        }
        for(auto it : mpp){
            for(int i=2; i<=1e3; i++){
                if(it.first*i*i > 1e6) break;
                int j = it.first;
                if(mpp.find(j) != mpp.end() && mpp.find(j*i) != mpp.end() && mpp.find(j*i*i) != mpp.end())
                    ans += (ll)mpp[j] * (ll)mpp[j*i] * (ll)mpp[j*i*i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}