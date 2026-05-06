#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = (int)x;
    for(int i=1; i<n; i++){
        ll val = (ll)arr[i-1]*a;
        val += b;
        val = val%c;
        arr[i] = (int)val;
    }
    vector<int> prefix(n);
    vector<int> suffix(n);
    for(int i=0; i<n; i++){
        if(i%k == 0){
            prefix[i] = arr[i];
        } else{
            prefix[i] = prefix[i-1] | arr[i];
        }
    }
    suffix[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--){
        if(i%k == k-1){
            suffix[i] = arr[i];
        } else{
           suffix[i] = suffix[i+1] | arr[i];
        }
    }
    int i = 0;
    int j = 0;
    int ans = 0;
    while(j < n){
        if(j-i+1 > k) i++;
        if(j-i+1 == k) ans ^= suffix[i] | prefix[j];
        j++;
    }
    cout << ans << endl;
    return 0;
}