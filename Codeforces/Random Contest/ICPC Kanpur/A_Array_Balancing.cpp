#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

bool allZero(vector<pair<int,int>>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++) if(arr[i].first != 0) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i].first = a[i] - b[i];
            arr[i].second = i+1;
        }
        int flag = 0;
        if(allZero(arr)) flag = 1;
        vector<vector<int>> ans;
        for(int i=0; i<2*n; i++){
            if(flag) break;
            vector<int> temp;
            sort(arr.begin(), arr.end());
            // for(auto it : arr) cout << it.first << " ";
            // cout << endl;
            for(int i=0; i<n; i++){
                if(i < n/2){
                    temp.push_back(arr[i].second);
                    arr[i].first++;
                } 
                else arr[i].first--;
            }
            ans.push_back(temp);
            if(allZero(arr)) flag = 1;
            if(flag) break;
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            for(auto it1 : it) cout << it1 << " ";
            cout << endl;
        }
    }
    return 0;
}