#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    vector<string> pattern = {"abc", "acb", "bac", "bca", "cab", "cba"};
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> cost(6, vector<int>(n));
    for(int i=0; i<6; i++){
        for(int j=0; j<n; j++){
            if(j == 0) cost[i][j] = 0;
            else cost[i][j] = cost[i][j-1];
            if(pattern[i][j%3] != s[j]) cost[i][j]++;
        }
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = INT_MAX;
        for(int i=0; i<6; i++){
            int val = cost[i][r];
            if(l > 0) val -= cost[i][l-1];
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}