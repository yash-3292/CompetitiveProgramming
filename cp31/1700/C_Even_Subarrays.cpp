#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int k = 32 - __builtin_clz(n);
        int val = pow(2, k) - 1;
        vector<int> freq(val+1, 0);
        freq[0]++;
        ll ans = 0;
        int xxor = 0;
        for(int i=0; i<n; i++){
            xxor = (xxor^arr[i]);
            for(int j=0; j*j<=val; j++){
                ans += (ll)(freq[(j*j)^xxor]);
            }
            freq[xxor]++;
        }
        ans = (ll)n*(n+1)/2 - ans;
        cout << ans << endl;
    }
    return 0;
}