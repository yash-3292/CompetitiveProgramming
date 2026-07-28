#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int l = 0;
        int g = 0;
        for(int j=0; j<n; j++){
            if(arr[j] < arr[i]) l++;
            else if(arr[j] > arr[i]) g++;
        }
        ans = min(ans, max(l,g));
    }
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