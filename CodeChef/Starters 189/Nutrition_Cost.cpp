#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<pair<int,int>> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i].first;
        for(int i=0; i<n; i++) cin >> nums[i].second;
        sort(nums.begin(), nums.end());
        vector<int> cost;
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            if(mpp[nums[i].first] == 0){
                cost.push_back(nums[i].second);
                mpp[nums[i].first] = 1;
            }
        }
        sort(cost.begin(), cost.end());
        int size = cost.size();
        int sum = 0;
        int maxi = 0;
        for(int i=0; i<size; i++){
            sum += cost[i];
            int val = c * (i+1) - sum;
            maxi = max(maxi, val);
        }
        cout << maxi << endl;
    }
    return 0;
}