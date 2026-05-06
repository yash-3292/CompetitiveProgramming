#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<int> h(n);
        vector<int> s(n);
        for(int i=0; i<n; i++) cin >> h[i];
        for(int i=0; i<n; i++) cin >> s[i];
        vector<ll> preSum(n);
        preSum[0] = (ll)h[0];
        for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + (ll)h[i];
        deque<int> dq;
        int i = 0;
        int j = 0;
        ll ans = 0;
        while(j < n){
            while(!dq.empty() && s[dq.back()] < s[j]) dq.pop_back();
            dq.push_back(j);
            while(i <= j){
                ll val = preSum[j];
                if(i > 0) val -= preSum[i-1];
                val += (ll)s[dq.front()];
                if(val < c){
                    
                }
            }
            // if(j-i+1 > k){
        //         if(dq.front() == i) dq.pop_front();
        //         i++;
        //     }
        //     if(j-i+1 == k) ans ^= arr[dq.front()];
        //     j++;
        // }
        // cout << ans << endl;
    }
    return 0;
}