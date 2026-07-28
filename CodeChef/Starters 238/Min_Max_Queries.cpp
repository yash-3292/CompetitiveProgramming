#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> maxi(n-1,0);
    vector<int> mini(n-1,0);
    for(int i=0; i<n-1; i++){
        maxi[i] = max(arr[i], arr[i+1]);
    }
    for(int i=0; i<n-1; i++){
        mini[i] = min(arr[i], arr[i+1]);
    }
    // for(auto it : maxi) cout << it << " ";
    // cout << endl;
    // for(auto it : mini) cout << it << " ";
    // cout << endl;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int u, x;
            cin >> u >> x;
            u--;
            arr[u] = x;
            if(u != 0){
                mini[u-1] = min(arr[u-1], arr[u]);
                maxi[u-1] = max(arr[u-1], arr[u]);
            } 
            if(u != n-1){
                mini[u] = min(arr[u], arr[u+1]);
                maxi[u] = max(arr[u], arr[u+1]);
            }
        } else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            if(l == r){
                cout << arr[l] << endl;
                continue;
            }
            int len = r-l+1;
            if(len%2==0){
                int x = (r+l-1)/2;
                cout << maxi[x] << endl;
            } else{
                int x = (l+r)/2;
                cout << max(mini[x], mini[x-1]) << endl;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}