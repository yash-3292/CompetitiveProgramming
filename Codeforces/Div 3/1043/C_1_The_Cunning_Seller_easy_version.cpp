#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    vector<ll> cost(22);
    cost[0] = 3;
    ll cnt = 1;
    for(int i=1; i<22; i++){
        cost[i] = cost[i-1]*3 + cnt;
        cnt *= 3;
    }
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int k = 0;
        ll val = 1;
        for(int i=0; i<21; i++){
            k++;
            val *= 3;
        }
        ll ans = 0;
        while(val){
            if(val > n){
                val /= 3;
                k--;
            } else{
                ans += (n/val)*cost[k];
                n %= val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}