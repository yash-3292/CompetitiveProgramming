#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        ll maxB = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            maxB += (ll)ceil((double)arr[i]/(double)x);
        }
        ll minB = (ll)ceil((double)sum/(double)x);
        cout << minB << " " << maxB << endl;
    }
    return 0;
}