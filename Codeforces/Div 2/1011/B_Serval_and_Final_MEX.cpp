#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<pair<int,int>> ans;
    int ind1 = -1;
    int ind2 = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            if(ind1 == -1) ind1 = i;
            else if(ind2 == -1) ind2 = i;
        }
    }
    if(ind1 == -1){
        ans.push_back({0, n-1});
    } else if(ind2 == -1){
        if(ind1 > 0){
            ans.push_back({ind1-1, ind1});
            ans.push_back({0, n-2});
        } else{
            ans.push_back({ind1, ind1+1});
            ans.push_back({0, n-2});
        }
    } else{
        if(arr[0] != 0){
            ans.push_back({1,n-1});
            ans.push_back({0,1});
        } else if(arr[n-1] != 0){
            ans.push_back({0, n-2});
            ans.push_back({0,1});
        } else{
            ans.push_back({0, 1});
            ans.push_back({1,n-2});
            ans.push_back({0,1});
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it.first+1 << " " << it.second+1 << endl;
    }
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