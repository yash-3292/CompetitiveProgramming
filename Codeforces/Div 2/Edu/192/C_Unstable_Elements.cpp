#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++) freq[arr[i]]++;
    vector<int> temp;
    for(auto it : freq) temp.push_back(it.second);
    sort(temp.begin(), temp.end());
    vector<pair<int,int>> temp1;
    for(auto it : temp){
        if(temp1.empty() || temp1.back().first != it){
            temp1.push_back({it,1});
        }  else{
            temp1.back().second++;
        }
    }
    int sz = temp1.size();
    int sum = 0;
    int cnt = 0;
    int ans = 0;
    for(int i=sz-1; i>=0; i--){
        sum += temp1[i].first * temp1[i].second;
        cnt += temp1[i].second;
        int val = sum - (temp1[i].first-1) * cnt;
        if(k < val) continue;
        if((k-val)%cnt == 0){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}