#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> vis(n+1, 0);
        vector<int> last(n);
        for(int i=n-1; i>=0; i--){
            last[i] = (!vis[arr[i]]);
            vis[arr[i]] = 1;
        }
        for(int i=0; i<=n; i++) vis[i] = 0;
        map<int,int> mpp;
        vector<int> ans;
        int l = 0;
        int r = 0;
        while(r < n){
            if(vis[arr[l]]){
                mpp.erase(arr[l]);
                l++;
                r = max(l, r);
                continue;
            }
            if(vis[arr[r]] || (!last[r])){
                if(!vis[arr[r]]){
                    mpp[arr[r]]++;
                } 
                r++;
                continue;
            }
            mpp[arr[r]]++;
            if(last[l]){
                ans.push_back(arr[l]);
                mpp.erase(arr[l]);
                vis[arr[l]] = 1;
            } else{
                int flag = 0;
                if(ans.size()&1){
                    int mini = mpp.begin()->first;
                    if(mini == arr[l]) flag = 1;
                } else{
                    int maxi = mpp.rbegin()->first;
                    if(maxi == arr[l]) flag = 1;
                }
                if(flag){
                    ans.push_back(arr[l]);
                    mpp.erase(arr[l]);
                    vis[arr[l]] = 1;
                } else{
                    mpp[arr[l]]--;
                    if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                }
            }
            l++;
            r = max(l, r);
        }
        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}