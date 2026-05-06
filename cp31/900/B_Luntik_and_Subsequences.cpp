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
        int one = 0;
        int zero = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 1) one++;
            if(arr[i] == 0) zero++;
        }
        ll ans = (ll)one * pow(2,(ll)zero);
        cout << ans << endl;
    }
    return 0;
}