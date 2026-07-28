#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m; 
    vector<int> arr(m);
    for(int i=0; i<m; i++) cin >> arr[i];
    for(int i=1; i<m; i++){
        if(arr[i] == 1){
            cout << 1 << endl;
            return;
        }
    }
    int maxi = arr[m-1];
    int ans = n - maxi + 1;
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