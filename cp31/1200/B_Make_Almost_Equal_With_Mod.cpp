#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isAnswer(vector<ll> &arr, ll n){
    int cnt = 0;
    map<ll,int> mpp;
    for(ll val : arr){
        if(mpp[val % n] == 0){
            cnt++;
            mpp[val % n] = 1;
        }
    }
    if(cnt == 2) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll ans = 2;
        while(ans <= 1e18){
            if(isAnswer(arr, ans)) break;
            ans *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}