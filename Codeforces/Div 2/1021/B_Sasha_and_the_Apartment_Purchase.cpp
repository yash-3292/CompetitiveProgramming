#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> arr1, arr2;
    for(int i=0; i<n; i++){
        arr1.push_back(arr[i]);
        if(i < k) continue;
        arr2.push_back(arr[i]);
    }
    for(int i=0; i<k; i++) arr1.pop_back();
    int val1 = arr1[(arr1.size()-1)/2];
    int val2 = arr2[(arr2.size())/2];
    int ans = val2-val1+1;
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