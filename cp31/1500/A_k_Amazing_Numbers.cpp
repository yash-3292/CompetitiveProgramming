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
        vector<int> prev(n+1,-1);
        map<int,int> dist;
        for(int i=0; i<n; i++){
            int distance = i - prev[arr[i]];
            if(dist.find(arr[i]) != dist.end()){
                dist[arr[i]] = max(dist[arr[i]], distance);
            } else{
                dist[arr[i]] = distance;
            }
            prev[arr[i]] = i;
        }
        vector<int> ans(n+1,-1);
        for(auto it : dist){
            int distance = n - prev[it.first];
            it.second = max(it.second, distance);
            if(ans[it.second] == -1) ans[it.second] = it.first;
        }
        int ansi = INT_MAX;
        for(int i=1; i<=n; i++){
            if(ans[i] != -1) ansi = min(ansi, ans[i]);
            if(ansi == INT_MAX) cout << -1 << " ";
            else cout << ansi << " ";
        }
        cout << endl;
    }
    return 0;
}