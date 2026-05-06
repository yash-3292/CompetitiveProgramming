#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    } 
    sort(arr.begin(), arr.end());
    while(q--){
        int k;
        cin >> k;
        unordered_map<int,int> mpp;
        for(int i=0; i<k; i++){
            int x;
            cin >> x;
            mpp[x] = 1;
        }
        int ans;
        for(int i=0; i<n; i++){
            if(mpp.find(arr[i].second) != mpp.end()) continue;
            ans = arr[i].first;
            break;
        }
        cout << ans << endl;
    }
    return 0;
}