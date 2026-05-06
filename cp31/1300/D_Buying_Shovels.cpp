#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int maxi = 1;
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                if(i <= k) maxi = max(maxi, i);
                if(n/i <= k) maxi = max(maxi, n/i);
            }
        }
        int ans = n/maxi;
        cout << ans << endl;
    }
    return 0;
}