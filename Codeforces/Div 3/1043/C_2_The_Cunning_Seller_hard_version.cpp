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
        ll n, k;
        cin >> n >> k;
        int p = 0;
        ll val = 1;
        for(int i=0; i<21; i++){
            p++;
            val *= 3;
        }
        ll ans = 0;
        vector<ll> deals(22, 0);
        ll totalDeal = 0;
        while(val){
            if(val > n){
                val /= 3;
                p--;
            } else{
                deals[p] = n/val;
                totalDeal += n/val;
                n %= val;
            }
        }
        if(totalDeal > k){
            cout << -1 << endl;
            continue;
        }
        for(int i=21; i>0; i--){
            if(deals[i] > 0){
                ll val = min((k-totalDeal)/2, deals[i]);
                deals[i] -= val;
                deals[i-1] += val*3;
                totalDeal += 2*val;
            } 
            if(totalDeal >= k) break;
        }
        for(int i=0; i<22; i++){
            ans += deals[i]*cost[i];
        }
        cout << ans << endl;
    }
    return 0;
}