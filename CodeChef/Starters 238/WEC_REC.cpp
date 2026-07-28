#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int i;
    for(i=1; i<n; i++){
        if(arr[i] != arr[i-1]) k--;
        if(k == 0) break;
    }
    int ans = min(x, i);
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