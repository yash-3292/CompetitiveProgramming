#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        ll mini = 1e18;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mini = min(mini, arr[i]);
        }
        sort(arr.begin(), arr.end());
        if(k >= 3){
            cout << 0 << endl;
            continue;
        }
        vector<ll> subs;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll val = arr[j] - arr[i];
                subs.push_back(val);
                mini = min(mini, val);
            }
        }
        if(k == 1){
            cout << mini << endl;
            continue;
        }
        for(ll val : subs){
            int pos = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
            if(pos != n) mini = min(mini, abs(val-arr[pos]));
            if(pos != 0) mini = min(mini, abs(val-arr[pos-1]));
        }
        cout << mini << endl;
    }
}