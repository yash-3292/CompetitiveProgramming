#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            arr[u] += w;
            arr[v] += w;
        }
        ll mini = 1e18;
        for(int i=1; i<=n; i++) mini = min(mini, arr[i]);
        cout << mini << endl;
    }
    return 0;
}