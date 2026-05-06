#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<int>& arr, vector<int>& vis, vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    if(!vis[arr[node]]){
        dfs(arr[node], arr, vis, temp);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<int> vis(n+1);
        int extra = 1;
        ll ans = 0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vector<int> temp;
                dfs(i, arr, vis, temp);
                int sz = temp.size();
                ans += (ll)(sz-1);
                sort(temp.begin(), temp.end());
                for(int i=1; i<sz; i++) if(temp[i] == 1+temp[i-1]) extra = -1;
            }
        }
        ans += extra;
        cout << ans << endl;
    }
    return 0;
}