#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> pref(n);
    vector<int> suf(n);
    pref[0] = arr[0];
    for(int i=1; i<n; i++){
        pref[i] = __gcd(pref[i-1], arr[i]);
    }
    suf[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        suf[i] = __gcd(suf[i+1], arr[i]);
    }
    ll sum  =0;
    sum += (ll)pref[n-1];
    for(int i=1; i<n-1; i++){
        sum += (ll)min(pref[i], suf[i]);
    }
    cout << sum << endl;
    return 0;
}