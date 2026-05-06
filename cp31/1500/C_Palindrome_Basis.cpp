#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = (ll)(1e9+7);

int main(){
    vector<int> arr;
    for(int i=1; i<=40000; i++){
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        if(t == s){
            arr.push_back(i);
        }
    }
    int sz = arr.size();
    int n = 40000;
    vector<int> prev(n+1, 0);

    for(int i=0; i<=n; i++){
        prev[i] = (i%arr[0] == 0);
    }
    for(int i=1; i<sz; i++){
        for(int target=0; target<=n; target++){
            ll notTake = prev[target];
            ll take = 0;
            if(arr[i] <= target) take = prev[target-arr[i]];
            ll ans = (take+notTake)%mod;
            prev[target] = ans;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        ll ans = prev[x];
        cout << ans << endl;
    }
    return 0;
}