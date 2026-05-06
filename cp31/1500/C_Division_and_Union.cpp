#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++){
            int l, r;
            cin >> l >> r;
            arr[i].push_back(l);
            arr[i].push_back(r);
            arr[i].push_back(i);
        }
        sort(arr.begin(), arr.end());
        int i;
        int maxi = arr[0][1];
        for(i=1; i<n; i++){
            if(maxi < arr[i][0]) break;
            maxi = max(maxi, arr[i][1]);
        }
        if(i == n){
            cout << -1 << endl;
            continue;
        }
        vector<int> ans(n);
        for(int j=0; j<n; j++){
            if(j < i){
                ans[arr[j][2]] = 1;
            } else{
                ans[arr[j][2]] = 2;
            }
        }
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}