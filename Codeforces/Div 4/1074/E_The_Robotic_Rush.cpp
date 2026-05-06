#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            arr.push_back({x, i});
        }
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            arr.push_back({x, -1});
        }
        string s;
        cin >> s;
        sort(arr.begin(), arr.end());
        vector<pair<int,int>> robot(n);
        int prevSpike = -1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i].second == -1){
                prevSpike = arr[i].first;
            } else{
                int ind = arr[i].second;
                if(prevSpike == -1) robot[ind].first = 1e6;
                else robot[ind].first = arr[i].first - prevSpike;
            }
        }
        prevSpike = -1;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i].second == -1){
                prevSpike = arr[i].first;
            } else{
                int ind = arr[i].second;
                if(prevSpike == -1) robot[ind].second = 1e6;
                else robot[ind].second = prevSpike - arr[i].first;
            }
        }
        vector<int> ans(k, 0);
        unordered_map<int,int> mppl, mppr;
        int maxL = 0;
        int maxR = 0;
        int val = 0;
        for(int i=0; i<k; i++){
            if(s[i] == 'R') val++;
            else val--;
            if(val > 0){
                if(maxR < val){
                    maxR = val;
                    mppr[maxR] = i;
                }
            } else if(val < 0){
                if(maxL < abs(val)){
                    maxL = abs(val);
                    mppl[maxL] = i;
                }
            }
        }
        for(auto it : robot){
            int mini = 1e9;
            if(mppl.find(it.first) != mppl.end()) mini = min(mini, mppl[it.first]);
            if(mppr.find(it.second) != mppr.end()) mini = min(mini, mppr[it.second]);
            if(mini < k){
                ans[mini]++;
            }
        }
        for(int i=1; i<k; i++) ans[i] += ans[i-1];
        for(auto it : ans) cout << n-it << " ";
        cout << endl;
    }
    return 0;
}