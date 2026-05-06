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
        int ans = 0;
        for(int j=1; j*j<=n; j++){
            if(n%j == 0){
                int k = j;
                int gcd = -1;
                for(int i=0; i<n; i++){
                    if(i+k<n){
                        int val = abs(arr[i]-arr[i+k]);
                        if(val != 0){
                            if(gcd == -1) gcd = val;
                            else gcd = __gcd(gcd, val);
                        }
                    }
                }
                if(gcd >= 2 || gcd == -1) ans++;
            }
        }
        for(int j=1; j*j<=n; j++){
            if(n%j == 0){
                int k = n/j;
                if((ll)k*(ll)k == (ll)n) continue;
                int gcd = -1;
                for(int i=0; i<n; i++){
                    if(i+k<n){
                        int val = abs(arr[i]-arr[i+k]);
                        if(val != 0){
                            if(gcd == -1) gcd = val;
                            else gcd = __gcd(gcd, val);
                        }
                    }
                }
                if(gcd >= 2 || gcd == -1) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}