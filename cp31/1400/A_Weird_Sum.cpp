#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    map<int,vector<int>> xmpp;
    map<int,vector<int>> ympp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            xmpp[arr[i][j]].push_back(i);
            ympp[arr[i][j]].push_back(j);
        }
    }
    ll ans = 0;
    for(auto it : xmpp){
        vector<int> nums(it.second);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<ll> preSum(size);
        preSum[0] = 0;
        for(int i=1; i<size; i++){
            preSum[i] = preSum[i-1] + (ll)nums[i-1];
        }
        for(int i=1; i<size; i++){
            ans += (ll)i * (ll)nums[i] - preSum[i];
        }
    }
    for(auto it : ympp){
        vector<int> nums(it.second);
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<ll> preSum(size);
        preSum[0] = 0;
        for(int i=1; i<size; i++){
            preSum[i] = preSum[i-1] + (ll)nums[i-1];
        }
        for(int i=1; i<size; i++){
            ans += (ll)i * (ll)nums[i] - preSum[i];
        }
    }
    cout << ans << endl;
    return 0;
}