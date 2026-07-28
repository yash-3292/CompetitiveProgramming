#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int mini = INT_MAX;
    for(int i=0; i<n; i++) mini = min(mini, arr[i]);
    int cnt = 0;
    for(int i=0; i<n; i++) if(arr[i] == mini) cnt++;
    if(cnt == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
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