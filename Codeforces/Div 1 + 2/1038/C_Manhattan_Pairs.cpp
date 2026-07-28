#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back({x[i], y[i], i+1});
    }
    sort(arr.begin(), arr.end());
    vector<pair<int,int>> arr1, arr2;
    for(int i=0; i<n; i++){
        if(i < n/2){
            arr1.push_back({arr[i][1], arr[i][2]});
        } else{
            arr2.push_back({arr[i][1], arr[i][2]});
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int i = 0;
    int j = 0;
    while(i+j < n/2){
        if(arr1[i].first <= arr2[j].first){
            i++;
        } else{
            j++;
        }
    }
    vector<pair<int,int>> ans;
    for(int k=0; k<j; k++){
        ans.push_back({arr1[k+i].second, arr2[k].second});
    }
    for(int k=0; k<i; k++){
        ans.push_back({arr1[k].second, arr2[k+j].second});
    }
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}