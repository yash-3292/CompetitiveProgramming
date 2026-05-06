#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

db f(int i, int j, int n, vector<int>& arr, vector<vector<db>>& dp){
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    db ans;
    if((j-i+1)%2 == n%2){
        db front = (db)arr[i] + f(i+1, j, n, arr, dp);
        db back = (db)arr[j] + f(i, j-1, n, arr, dp);
        ans = (front+back)/2;
    } else{
        db front = f(i+1, j, n, arr, dp);
        db back = f(i, j-1, n, arr, dp);
        ans = (front+back)/2;
    }

    return dp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<db>> dp(n, vector<db>(n, -1));
        db ans = f(0, n-1, n, arr, dp);
        cout << setprecision(10) <<  ans << endl;
    }
    return 0;
}