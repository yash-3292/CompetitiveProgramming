#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n-1);
    vector<int> degree(n+1,0);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        arr[i] = {u,v};
    }
    int x = 0;
    vector<int> ans(n-1,-1);
    for(int i=0; i<n-1; i++){
        if(x >= 3) break;
        if(degree[arr[i].first] == 1 || degree[arr[i].second] == 1){
            ans[i] = x;
            x++;
        }
    }
    for(int i=0; i<n-1; i++){
        if(ans[i] == -1){
            ans[i] = x;
            x++;
        }
    }
    for(auto it : ans) cout << it << endl;
    return 0;
}