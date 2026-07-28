#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int mini = 1e9+10;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > mini){
            arr2.push_back(arr[i]);
        } else{
            arr1.push_back(arr[i]);
            mini = min(mini, arr[i]);
        }
    }
    reverse(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    if(arr2.size()){
        int val = arr2[0];
        while(!arr1.empty() && arr1.back() > val+1){
            arr2.push_back(arr1.back());
            arr1.pop_back();
        }
    }
    sort(arr2.begin(), arr2.end());
    for(auto it : arr1) cout << it << " ";
    for(auto it : arr2) cout << it+1 << " ";
    cout << endl;
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