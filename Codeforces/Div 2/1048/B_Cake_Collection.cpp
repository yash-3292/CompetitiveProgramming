#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        ll ans = 0;
        for(int i=n-1; i>=0; i--){
            ans += (ll)arr[i]*(ll)m;
            m--;
            if(m == 0) break;
        }
        cout << ans << endl;    
    }
    return 0;
}