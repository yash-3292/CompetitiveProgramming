#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll gcd = arr[0];
        for(int i=1; i<n; i++){
            gcd = __gcd(gcd, arr[i]);
        }
        for(int i=2; i<=1e3; i++){
            ll val = __gcd(gcd, (ll)i);
            if(val == 1){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}