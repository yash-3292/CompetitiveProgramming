#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<vector<int>> divi(n);
        for(int i=0; i<n; i++){
            int x = arr[i];
            for(int j=1; j*j<=x; j++){
                if(x%j == 0){
                    if(j <= m) divi[i].push_back(j);
                    if(x/j != j && x/j <= m) divi[i].push_back(x/j);
                }
            }
        }
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        vector<int> cnt(m+1, 0);
        while(j < n){
            for(auto it : divi[j]){
                cnt[it]++;
            }
            while(i <= j){
                int f = 1;
                for(auto it : divi[i]){
                    if(cnt[it] <= 1){
                        f = 0;
                        break;
                    }
                }
                if(!f) break;
                for(auto it : divi[i]){
                    cnt[it]--;
                }
                i++;
            }
            int f = 1;
            for(int k=1; k<=m; k++){
                if(cnt[k] == 0){
                    f = 0;
                    break;
                }
            }
            if(f){
                ans = min(ans, arr[j]-arr[i]);
            }
            j++;
        }
        if(ans == INT_MAX){
            cout << -1 << endl;
        } else{
            cout << ans << endl;
        }
    }
    return 0;
}