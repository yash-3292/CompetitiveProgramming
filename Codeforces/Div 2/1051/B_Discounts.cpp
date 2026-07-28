#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> b(k);
    for(int i=0; i<k; i++) cin >> b[i];
    ll ans = 0;
    sort(arr.begin(), arr.end());
    sort(b.begin(), b.end());
    for(auto it : b){
        for(int i=0; i<it; i++){
            if(arr.empty()) break;
            if(i != it-1){
                ans += (ll)arr.back();
            }
            arr.pop_back();
        }
        if(arr.empty()) break;
    }
    while(!arr.empty()){
        ans += (ll)arr.back();
        arr.pop_back();
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}