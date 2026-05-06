#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<int> preSum(n+1,0);
        for(int i=1; i<=n; i++){
            preSum[i] = preSum[i-1];
            if(abs(arr[i]) == 2) preSum[i]++;
        }
        vector<int> flag(n+1,0);
        for(int i=1; i<=n; i++){
            flag[i] = flag[i-1];
            if(arr[i] < 0) flag[i] = !flag[i];
        }
        int prev = 0;
        vector<pair<int,int>> ranges;
        for(int i=1; i<=n; i++){
            if(arr[i] == 0){
                if(prev+1 <= i-1){
                    ranges.push_back({prev+1, i-1});
                }
                prev = i;
            } 
        }
        if(prev+1 <= n){
            ranges.push_back({prev+1, n});
        }
        int maxi = 0;
        int lans =  1;
        int rans = 0;
        for(auto it : ranges){
            int l = it.first;
            int r = it.second;
            int temp = l;
            while(temp <= r){
                if(flag[temp-1] == flag[r]){
                    int cnt = preSum[r] - preSum[temp-1];
                    if(cnt > maxi){
                        lans = temp;
                        rans = r;
                        maxi = cnt;
                    }
                    break;
                }
                temp++;
            }
            temp = r;
            while(temp >= l){
                if(flag[l-1] == flag[temp]){
                    int cnt = preSum[temp] - preSum[l-1];
                    if(cnt > maxi){
                        lans = l;
                        rans = temp;
                        maxi = cnt;
                    }
                    break;
                }
                temp--;
            }
        }
        pair<int,int> ans = {lans-1, n-rans};
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}