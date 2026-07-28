#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll k, x, a;
    cin >> k >> x >> a;
    ll preSum = 1; 
    a -= 1;
    for(ll i=2; i<=x+1; i++){
        ll y = preSum / (k-1);
        y++;
        if(a < y){
            cout << "NO" << endl;
            return;
        }
        a -= y;
        preSum += y;
        // cout << y << " ";
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}