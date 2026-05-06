#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> suffGCD(n);
    suffGCD[n-1] = -1;
    for(int i=n-2; i>=0; i--){
        if(suffGCD[i+1] == -1){
            suffGCD[i] = arr[i+1];
        } else{
            suffGCD[i] = __gcd(arr[i+1], suffGCD[i+1]);
        }
    }
    ll ans = -1;
    for(int i=0; i<n-1; i++){
        ll val = (ll)arr[i]*(ll)suffGCD[i] / __gcd((ll)arr[i],(ll)suffGCD[i]);
        if(ans == -1) ans = val;
        else ans = __gcd(ans, val);
    }
    cout << ans << endl;
    return 0;
}