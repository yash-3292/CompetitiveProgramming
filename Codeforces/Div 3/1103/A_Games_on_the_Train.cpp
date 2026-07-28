#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int mini = arr[0];
    int maxi = arr[0];
    for(int i=0; i<n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    cout << maxi - mini +1 << endl;
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