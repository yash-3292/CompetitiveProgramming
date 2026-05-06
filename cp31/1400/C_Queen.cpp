#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> temp;
    for(int i=0; i<n; i++){
        int p, c;
        cin >> p >> c;
        if(p != -1) adj[p].push_back({i+1,c});
        if(c) temp.push_back(i+1);
    }
    vector<int> ans;
    for(int val : temp){
        int flag = 1;
        for(auto it : adj[val]){
            if(it.second == 0) flag = 0;
        }
        if(flag) ans.push_back(val);
    }
    if(ans.size() == 0) cout << -1 << endl;
    else{
        for(auto val : ans) cout << val << " ";
        cout << endl;
    }
    return 0;
}