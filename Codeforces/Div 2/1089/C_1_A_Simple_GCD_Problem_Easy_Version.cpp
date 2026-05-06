#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        int ans = 0;
        for(int i=0; i<n; i++){
            int val;
            if(i == 0){
                val = __gcd(a[i], a[i+1]);
            } else if(i == n-1){
                val = __gcd(a[i], a[i-1]);
            } else{
                int gcd1 = __gcd(a[i], a[i+1]);
                int gcd2 = __gcd(a[i], a[i-1]);
                val = (gcd1/__gcd(gcd1, gcd2)) * gcd2;
            }
            if(val <= b[i] && val != a[i]){
                ans++;
                a[i] = val;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}