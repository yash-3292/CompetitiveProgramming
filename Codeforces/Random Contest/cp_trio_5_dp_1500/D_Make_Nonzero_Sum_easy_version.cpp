#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n&1){
            cout << -1 << endl;
            continue;
        }
        vector<pair<int,int>> ans;
        for(int i=0; i<n; i+=2){
            if(arr[i] == arr[i+1]){
                ans.push_back({i+1, i+2});
            } else{
                ans.push_back({i+1, i+1});
                ans.push_back({i+2, i+2});
            }
        }
        cout << ans.size() << endl;
        for(auto it : ans) cout << it.first << " " << it.second << endl;
    }
    return 0;
}