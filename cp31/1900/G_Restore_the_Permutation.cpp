#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<pair<int,int>> arr;
    vector<int> vis(n+1,0);
    for(int i=0; i<n/2; i++){
        int x;
        cin >> x;
        ans[2*i+1] = x;
        arr.push_back({x,i});
        vis[x] = 1;
    }
    vector<int> left;
    for(int i=n; i>=1; i--){
        if(!vis[i]) left.push_back(i);
    }
    sort(arr.begin(), arr.end());
    priority_queue<int> pq;
    for(auto it : left){
        while(!arr.empty() && arr.back().first > it){
            pq.push(arr.back().second);
            arr.pop_back();
        }
        if(pq.empty()){
            cout << -1 << endl;
            return;
        }
        int ind = pq.top();
        pq.pop();
        ans[ind*2] = it;
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}