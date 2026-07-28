#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=1; i<n; i++) if(arr[i] == arr[i-1]){
        cout << -1 << endl;
        return;
    }
    for(auto it : arr) cout << it << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}