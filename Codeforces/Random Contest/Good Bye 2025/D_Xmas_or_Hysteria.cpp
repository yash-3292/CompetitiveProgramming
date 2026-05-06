#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i+1;
        } 
        sort(arr.begin(), arr.end());
        if(m > n/2){
            cout << -1 << endl;
            continue;
        }
        if(m <= n/2 && m > 0){
            vector<pair<int,int>> ans;
            int j = 0;
            while(j < n-2*m){
                ans.push_back({arr[j+1].second, arr[j].second});
                j++;
            }
            int i = n-1;
            while(j < i){
                ans.push_back({arr[i].second, arr[j].second});
                i--;
                j++;
            }
            cout << ans.size() << endl;
            for(auto it : ans){
                cout << it.first << " " << it.second << endl;
            }
            continue;
        }
        vector<pair<int,int>> ans;
        ll val = (ll)arr[n-1].first;
        int j;
        for(j=n-2; j>=0; j--){
            val -= (ll)arr[j].first;
            if(val < 0) break;
        }
        if(val > 0){
            cout << -1 << endl;
            continue;
        }
        for(int i=0; i<n-1; i++){
            if(i < j){
                ans.push_back({arr[i].second, arr[i+1].second});
            } else{
                ans.push_back({arr[i].second, arr[n-1].second});
            }
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it.first << " "  << it.second << endl;
        }
    }
    return 0;
}