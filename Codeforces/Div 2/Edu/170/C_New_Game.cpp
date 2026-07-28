#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    vector<pair<int,int>> temp;
    for(auto it : freq){
        temp.push_back(it);
    }
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = 0;
    while(j < temp.size()){
        if(j != 0 && temp[j-1].first+1 != temp[j].first){
            sum = temp[j].second;
            i = j;
        } else{
            sum += temp[j].second;
        }

        if(j-i+1 > k){
            sum -= temp[i].second;
            i++;
        }

        ans = max(ans, sum);

        j++;
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