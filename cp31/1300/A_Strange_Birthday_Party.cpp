#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> k(n), c(m);
        for(int i=0; i<n; i++) cin >> k[i];
        for(int i=0; i<m; i++) cin >> c[i];
        sort(k.begin(), k.end(), greater<int>());
        int j = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(j+1 <= k[i]){
                ans += (ll)c[j];
                j++;
            } else{
                ans += (ll)c[k[i]-1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}