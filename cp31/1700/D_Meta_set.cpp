#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(vector<int>& arr){
    ll ans = 0;
    for(auto it : arr){
        ans = ans*3 + (ll)it;
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(k));
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> arr[i][j];
        }
    }
    unordered_map<ll,int> mpp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            vector<int> temp(k);
            for(int ind=0; ind<k; ind++){
                if(arr[i][ind] == arr[j][ind]){
                    temp[ind] = arr[i][ind];
                    continue;
                } 
                int val = arr[i][ind]+arr[j][ind];
                if(val == 1){
                    temp[ind] = 2;
                } else if(val == 2){
                    temp[ind] = 1;
                } else{
                    temp[ind] = 0;
                }
            }
            ll val = calc(temp);
            mpp[val]++;
        }
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll val = calc(arr[i]);
        if(mpp.find(val) != mpp.end()){
            ll x = mpp[val];
            ans += ((x)*(x-1))/2;
        }
    }
    cout << ans << endl;
    return 0;
}