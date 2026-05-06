#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> arr(n);
        ll ans = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
        }
        for(int i=0; i<n; i++){
            cin >> arr[i].second;
        }
        for(int i=0; i<n; i++){
            if(arr[i].first > arr[i].second) swap(arr[i].first, arr[i].second);
            ans += (ll)arr[i].second - (ll)arr[i].first;
        }
        sort(arr.begin(), arr.end());
        int flag = 1;
        for(int i=0; i<n-1; i++){
            if(arr[i].second >= arr[i+1].first){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << ans << endl;
            continue;
        }
        ll mini = INT_MAX;
        for(int i=0; i<n-1; i++){
            mini = min(mini, (ll)arr[i+1].first - (ll)arr[i].second);
        }
        ans += 2*mini;
        cout << ans << endl;
    }
    return 0;
}