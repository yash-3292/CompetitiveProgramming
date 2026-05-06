#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int i, vector<int>& arr, map<int,vector<int>>& mpp, vector<int>& dp){
    if(i == -1) return true;
    if(i < -1) return false;

    if(dp[i] != -1) return dp[i];
    bool flag = f(i-arr[i]-1, arr, mpp, dp);
    if(mpp.find(i) != mpp.end()){
        for(auto it : mpp[i]){
            flag = (flag | f(it-1, arr, mpp, dp));
        }
    }

    return dp[i] = flag;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mpp[i+arr[i]].push_back(i);
        } 
        vector<int> dp(n, -1);
        bool flag = f(n-1, arr, mpp, dp);
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}