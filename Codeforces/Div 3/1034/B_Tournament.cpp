#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> arr(n);
    int maxi = 0;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) maxi = max(maxi, arr[i]);
    if(k > 1){
        cout << "YES" << endl;
        return;
    }
    if(arr[j-1] == maxi) cout << "YES" << endl;
    else cout << "NO" << endl;
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