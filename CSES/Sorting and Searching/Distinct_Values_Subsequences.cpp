#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main(){
    int n;  
    cin >> n;
    vector<int> arr(n);
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        mpp[x]++;
    } 
    ll ans = 1;
    for(auto it : mpp){
        ans = (ll)(it.second+1)*ans;
        ans = ans%mod;
    }
    ans--;
    cout << ans << endl;
    return 0;
}