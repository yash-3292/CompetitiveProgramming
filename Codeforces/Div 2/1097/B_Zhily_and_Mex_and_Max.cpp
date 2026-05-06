#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(vector<ll>& arr){
    int n = arr.size();
    ll ans = 0;
    ll maxi = 0;
    ll mexx = 0;
    unordered_map<ll,ll> mpp;
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
        mpp[arr[i]]++;
        while(mpp.find(mexx) != mpp.end()){
            mexx++;
        }
        ans += maxi;
        ans += mexx; 
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<ll> temp;
        temp.push_back(arr[n-1]);
        arr.pop_back();
        vector<int> temp2;
        for(int i=0; i<n-1; i++){
            if(temp.back() == arr[i]) temp2.push_back(arr[i]);
            else temp.push_back(arr[i]);
        }
        for(auto it : temp2){
            temp.push_back(it);
        }
        ll ans = f(temp);
        cout << ans << endl;
    }
    return 0;
}