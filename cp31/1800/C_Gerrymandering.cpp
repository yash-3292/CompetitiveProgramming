#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int fcal(char x, char y, char z){
    int val = 0;
    if(x == 'A') val++;
    if(y == 'A') val++;
    if(z == 'A') val++;

    if(val >= 2) return 1;
    return 0;
}

int f(int i, int opt, int n, string& s1, string& s2, vector<vector<int>>& dp){
    if(i == n) return 0;

    if(dp[i][opt] != -1) return dp[i][opt];

    int ans;
    if(opt == 0){
        int val1 = fcal(s1[i], s2[i], s2[i+1]) + f(i+1, 1, n, s1, s2, dp);
        int val2 = fcal(s1[i], s2[i], s1[i+1]) + f(i+2, 2, n, s1, s2, dp);
        int val3 = fcal(s1[i], s1[i+1], s1[i+2]) + fcal(s2[i], s2[i+1], s2[i+2]) + f(i+3, 0, n, s1, s2, dp);
        ans = max(val1, max(val2, val3));
    } else if(opt == 1){
        int j = i+1;
        if(j == n-1){
            ans = fcal(s1[i], s1[j], s2[j]);
        } else{
            int val1 = fcal(s1[i], s1[j], s2[j]) + f(i+2, 0, n, s1, s2, dp);
            int val2 = fcal(s1[i], s1[i+1], s1[i+2]) + fcal(s2[j], s2[j+1], s2[j+2]) + f(i+3, 1, n, s1, s2, dp);
            ans = max(val1, val2);
        }
    } else{
        int j = i-1;
        if(i == n-1){
            ans = fcal(s1[i], s2[i], s2[j]);
        } else{
            int val1 = fcal(s1[i], s2[i], s2[j]) + f(i+1, 0, n, s1, s2, dp);
            int val2 = fcal(s1[i], s1[i+1], s1[i+2]) + fcal(s2[j], s2[j+1], s2[j+2]) + f(i+3, 2, n, s1, s2, dp);
            ans = max(val1, val2);
        }
    }

    return dp[i][opt] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = f(0, 0, n, s1, s2, dp);
        cout << ans << endl;
    }
    return 0;
}