#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int maxi = 0;
    int k = 0;
    vector<int> ind;
    for(int i=0; i<n; i++){
        if(arr[i] >= maxi){
            maxi = max(maxi, arr[i]);
        } else{
            ind.push_back(i);
            k = max(k, maxi-arr[i]);
        }
    }
    unordered_map<int,int> vis;
    for(auto it : ind){
        vis[it] = 1;
        arr[it] += k;
    }
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            if(vis.find(i) == vis.end()){
                arr[i] += k;
            }
        }
    }
    if(is_sorted(arr.begin(), arr.end())) cout << "YES" << endl;
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