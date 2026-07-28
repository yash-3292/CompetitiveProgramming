#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int o = 0;
    int maxi = 0;
    ll sum = 0;
    for(int i=0; i<n; i++){
        if(arr[i]&1){
            o++;
        }
        maxi = max(maxi, arr[i]);
        sum += (ll)arr[i];
    }
    if(o == 0 || o == n){
        cout << maxi << endl;
        return;
    }
    int val = o - 1;
    sum -= val;
    cout << sum << endl;
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