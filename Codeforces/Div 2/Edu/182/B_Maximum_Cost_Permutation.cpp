#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> vis(n+1, 0);
    for(int i=0; i<n; i++){
        vis[arr[i]] = 1;
    }
    vector<int> temp;
    for(int i=1; i<=n; i++) if(!vis[i]) temp.push_back(i);
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            arr[i] = temp.back();
            temp.pop_back();
        }
    }
    int l = n+1;
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            l = i+1;
            break;
        }
    }
    int r = 0;
    for(int i=n-1; i>=0; i--){
        if(arr[i] != i+1){
            r = i+1;
            break;
        }
    }
    int ans = 0;
    if(l < r) ans = r-l+1;
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