#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = n;
    for(int i=0; i<n; i++){
        int g = 0;
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i]) g++;
        }
        ans = min(ans, g+i);
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