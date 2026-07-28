#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=2; i<n; i++){
        if(arr[i-2]%arr[i-1] == arr[i]) continue;
        cout << -1 << endl;
        return;
    }
    cout << arr[0] << " " << arr[1] << endl;
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