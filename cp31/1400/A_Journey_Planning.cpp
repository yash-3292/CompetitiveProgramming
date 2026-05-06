#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int,ll> mpp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mpp[arr[i]-i-1] += (ll)arr[i];
    }
    ll maxi = 0;
    for(auto it : mpp){
        maxi = max(maxi, it.second);
    }
    cout << maxi << endl;
    return 0;
}