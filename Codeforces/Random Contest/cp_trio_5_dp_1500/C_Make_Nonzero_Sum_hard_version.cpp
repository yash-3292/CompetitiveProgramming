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
        vector<pair<int,int>> temp;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                temp.push_back({i, arr[i]});
            }
        }
        int m = temp.size();
        if(m&1){
            cout << -1 << endl;
            continue;
        }
        vector<pair<int,int>> ans;
        if(temp.size() == 0){
            ans.push_back({0, n-1});
        } else if(temp[0].first > 0) ans.push_back({0, temp[0].first-1});
        for(int i=0; i<m; i+=2){
            if(i >= 2){
                if(temp[i].first-temp[i-1].first > 1){
                    ans.push_back({temp[i-1].first+1, temp[i].first-1});
                }
            }
            if(temp[i].second == temp[i+1].second){
                if(temp[i].first+1 == temp[i+1].first){
                    ans.push_back({temp[i].first, temp[i].first+1});
                } else{
                    ans.push_back({temp[i].first, temp[i].first});
                    if(temp[i+1].first-temp[i].first > 2){
                        ans.push_back({temp[i].first+1, temp[i+1].first-2});
                    }
                    ans.push_back({temp[i+1].first-1, temp[i+1].first});
                }
            } else{
                ans.push_back({temp[i].first, temp[i].first});
                if(temp[i].first+1<=temp[i+1].first-1) ans.push_back({temp[i].first+1, temp[i+1].first-1});
                ans.push_back({temp[i+1].first, temp[i+1].first});
            }
        } 
        if(temp.size() != 0 && temp[m-1].first < n-1) ans.push_back({temp[m-1].first+1, n-1});
        cout << ans.size() << endl;
        for(auto it : ans) cout << it.first+1 << " " << it.second+1 << endl;
    }
    return 0;
}