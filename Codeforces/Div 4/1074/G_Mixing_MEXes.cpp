#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<ll>> arr;
        ll total = 0;
        for(ll i=0; i<n; i++){
            ll l;
            cin >> l;
            total += l;
            vector<ll> temp(l);
            for(ll j=0; j<l; j++) cin >> temp[j];
            arr.push_back(temp);
        }
        map<ll,ll> mpp;
        ll mexSum = 0;
        vector<ll> mex(n);
        for(ll i=0; i<n; i++){
            sort(arr[i].begin(), arr[i].end());
            ll val = 0;
            ll l = arr[i].size();
            for(ll j=0; j<l; j++){
                if(arr[i][j] < val) continue;
                if(arr[i][j] == val) val++;
                else break;
            } 
            mex[i] = val;
            val++;
            for(ll j=0; j<l; j++){
                if(arr[i][j] < val) continue;
                if(arr[i][j] == val) val++;
                else break;
            } 
            mexSum += mex[i];
            mpp[mex[i]] += (val-mex[i]);
        }
        ll ans = mexSum * total * (n-1);
        for(ll i=0; i<n; i++){
            ll l = arr[i].size();
            for(ll j=0; j<l; j++){
                if(arr[i][j] < mex[i]){
                    bool dup = false;
                    if(j!=0 && arr[i][j-1] == arr[i][j]) dup = true;
                    if(j!=l-1 && arr[i][j] == arr[i][j+1]) dup = true;
                    if(!dup) ans -= (mex[i]-arr[i][j])*(n-1);
                } 
                if(mpp.find(arr[i][j]) != mpp.end()){
                    ans += mpp[arr[i][j]];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}