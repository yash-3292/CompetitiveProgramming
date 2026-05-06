#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int,int> mpp;
        map<int,int> vis;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x] = 1;
        }
        int flag = 1;
        vector<int> ans;
        for(auto it : mpp){
            int val = it.first;
            if(vis.find(val) == vis.end()){
                ans.push_back(val);
            }
            for(int i=2; i*val<=k; i++){
                int nval = i*val;
                if(mpp.find(nval) == mpp.end()){
                    flag = 0;
                    break;
                }
                vis[nval] = 1;
            }
            if(!flag) break;
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        } 
        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}