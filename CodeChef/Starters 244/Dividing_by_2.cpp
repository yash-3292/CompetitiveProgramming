#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int,int> mpp;
    for(int i=0; i<n; i++){
        int x = arr[i];
        while(x != 0){
            mpp[x]++;
            x /= 2;
        }
    }
    int val = 1;
    for(auto it : mpp){
        if(it.second == n){
            val = max(val, it.first);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int x = arr[i];
        while(x != val){
            x /= 2;
            ans++;
        }
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