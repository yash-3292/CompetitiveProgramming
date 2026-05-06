#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,int> mpp;
    mpp[0]++;
    ll sum = 0;
    ll cnt = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        cnt += mpp[sum-x];
        mpp[sum]++;
    }
    cout << cnt << endl;
    return 0;
}