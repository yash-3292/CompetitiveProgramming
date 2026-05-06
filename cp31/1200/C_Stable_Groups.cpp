#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<ll> gap;
    for(int i=1; i<n; i++){
        if(arr[i] - arr[i-1] > x){
            gap.push_back(arr[i] - arr[i-1]);
        }
    }
    sort(gap.begin(), gap.end());
    int size = gap.size();
    int i = 0;
    while(i != size){
        ll req = gap[i] / x;
        if(gap[i] % x != 0) req++;
        req--;
        if(req > k) break;
        k -= req;
        i++;
    }
    int total = size - i + 1;
    cout << total << endl;
    return 0;
}