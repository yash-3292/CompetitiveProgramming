#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, vector<int>& arr){
    vector<int> vis(mid);
    vector<int> temp;
    for(auto val : arr){
        if(val < mid && !vis[val]){
            vis[val] = 1;
        } else{
            temp.push_back(val);
        }
    }
    int sz = temp.size();
    int j = 0;
    for(int i=0; i<mid; i++){
        if(vis[i]) continue;
        while(j < sz && (temp[j]-1)/2 < i){
            j++;
        }
        if(j == sz) return false;
        j++;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = n;
    int ans = 0;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(check(mid, arr)){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}