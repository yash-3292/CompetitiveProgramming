#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> ans;
        ll temp = 1e17;
        while(temp >= 10){
            ll val = temp+1;
            if(n%val == 0){
                ans.push_back(n/val);
            }
            temp /= 10;
        }
        if(ans.size() == 0){
            cout << 0 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for(ll val : ans) cout << val << " ";
        cout << endl;
    }
    return 0;
}