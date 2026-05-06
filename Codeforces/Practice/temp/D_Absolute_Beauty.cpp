#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
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
    }
    return 0;
}