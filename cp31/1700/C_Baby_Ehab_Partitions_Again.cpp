#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int k, vector<int>& arr, vector<vector<int>>& dp){
    if(k == 0) return 1;
    if(i < 0) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    int notTake = f(i-1, k, arr, dp);
    int take = 0;
    if(k >= arr[i]) take = f(i-1, k-arr[i], arr, dp);
    int ans = (take | notTake);

    return dp[i][k] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    if(sum&1){
        cout << 0 << endl;
        return 0;
    }
    int k = sum/2;
    vector<vector<int>> dp(n, vector<int>(k+1, -1)); 
    int ans = f(n-1, k, arr, dp);
    if(!ans){
        cout << 0 << endl;
        return 0;
    }
    int mini = INT_MAX;
    int ind = -1;
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int cnt = 0;
        while(temp%2 == 0){
            temp /= 2;
            cnt++;
        }
        if(cnt < mini){
            mini = cnt;
            ind = i;
        }
    }
    cout << 1 << endl;
    cout << ind+1 << endl;
    return 0;
}