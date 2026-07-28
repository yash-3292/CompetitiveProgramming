#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = INT_MAX;
    for(int i=1; i<=1000; i++){
        int val = 0;
        for(int j=0; j<n; j++){
            val = max(val, abs(i-arr[j]));
        }
        ans = min(ans, val);
    }
    cout << ans << endl;
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