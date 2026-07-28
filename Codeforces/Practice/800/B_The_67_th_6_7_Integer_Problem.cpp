#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n = 7;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans, -1*sum+2*arr[i]);
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