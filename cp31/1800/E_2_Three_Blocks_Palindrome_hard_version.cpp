#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int l, int r, vector<vector<int>>& pre){
    if(l > r) return 0;
    int maxi = 0;
    for(int i=1; i<=200; i++){
        int val = pre[r][i];
        if(l != 0) val -= pre[l-1][i];
        maxi = max(maxi, val);
    }
    return maxi;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<int>> pre(n, vector<int>(201,0));
        for(int i=0; i<n; i++){
            if(i != 0) pre[i] = pre[i-1];
            pre[i][arr[i]]++;
        }
        int ans = 1;
        for(int d=1; d<=200; d++){
            int i = 0;
            int j = n-1; 
            int cnt = 0;
            while(i < j){
                while(i < j){
                    if(arr[i] == d) break;
                    i++;
                }
                while(i < j){
                    if(arr[j] == d) break;
                    j--;
                }
                if(i >= j) break;
                cnt++;
                int val = 2*cnt + f(i+1, j-1, pre);
                ans = max(ans, val);
                i++;
                j--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}