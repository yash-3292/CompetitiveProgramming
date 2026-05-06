#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> prev(k+1,0);
        vector<pair<int,int>> jump(k+1, make_pair(0,0));
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            int jumpi = i - prev[arr[i]];
            if(jumpi >= jump[arr[i]].first){
                jump[arr[i]].second = jump[arr[i]].first;
                jump[arr[i]].first = jumpi;
            } else if(jumpi > jump[arr[i]].second){
                jump[arr[i]].second = jumpi;
            }
            prev[arr[i]] = i+1;
        }
        int mini = 1e6;
        for(int i=1; i<=k; i++){
            int jumpi = n - prev[i];
            if(jumpi >= jump[i].first){
                jump[i].second = jump[i].first;
                jump[i].first = jumpi;
            } else if(jumpi > jump[i].second){
                jump[i].second = jumpi;
            }
            int val = max(jump[i].first/2, jump[i].second);
            mini = min(mini, val);
        }
        cout << mini << endl;
    }
    return 0;
}