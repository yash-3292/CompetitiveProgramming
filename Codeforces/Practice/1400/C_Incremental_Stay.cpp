#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(2*n);
        for(int i=0; i<2*n; i++) cin >> arr[i];
        ll val = 0;
        for(int i=0; i<n; i++) val -= (ll)arr[i];
        for(int i=n; i<2*n; i++) val += (ll)arr[i];
        vector<ll> ans;
        ans.push_back(val);
        for(int i=0; i<n-1; i++){
            ll dif = arr[n+i] - arr[n-i-1];
            cout << n+i << " " << n-i-1 << endl;
            val -= dif*2;
            if(i > 0){
                ll dif1 = arr[n+i-1] - arr[n-i];
                val += dif1;
            }
            cout << val << endl;
            ans.push_back(val);
        }
        reverse(ans.begin(), ans.end());
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}