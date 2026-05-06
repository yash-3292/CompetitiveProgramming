#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;
ll inv2 = 500000004;

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> arr(q);
    vector<ll> ans(n, 0);
    for(int i=0; i<q; i++) cin >> arr[i];
    ll sum = 0;
    for(int i=q-1; i>=0; i--){
        ll val = (sum * inv2)%mod;
        ans[arr[i]-1] = (ans[arr[i]-1] + val)%mod;
        sum = (sum + arr[i])%mod;
        sum = (sum * inv2)%mod;
        // cout << "here : " << sum << endl;
    }
    ans[0] = (ans[0] + sum)%mod;
    for(auto it : ans){
        cout << it << endl;
    }
    return 0;
}