#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k, s, m;
        cin >> n >> k >> s >> m;
        vector<ll> arr(n+1, 0);
        ll x = s/k;
        ll y = s%k;
        arr[x] = k-y;
        if(y) arr[x+1] = y;
        ll ans = 0;
        if(arr[m]){
            if(m == 1 || m == n)  ans = arr[m];
            else{
                arr[m-1] += arr[m]/2;
                arr[m+1] += arr[m]/2;
                arr[m] %= 2;
                if(arr[m]){
                    if(arr[m-1] && 1 < m-1) ans = 0;
                    else if(arr[m+1] && m+1 < n) ans = 0;
                    else ans = 1;
                }
            }
        } 
        cout << ans << endl;
    }
    return 0;
}